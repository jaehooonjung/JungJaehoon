#include "Charlie.h"



Charlie::Charlie()
{
}

void Charlie::CharlieInit(HDC hdc)
{
	//.Init(HDC hdc, LPCTSTR bitmapname, POINT pos)
	//.Init(HDC hdc, LPCTSTR backgroundbitmapname, LPCTSTR bitmapname, POINT startpos, POINT endpos)
	m_CharacterMotion = CHARACTER_MOTION_MOVE_1;
	POINT postmp;
	postmp.x = CHARACTER_X_POSDEFAULT + START_POS_X;
	postmp.y = CHARACTER_Y_POSDEFAULT + START_POS_Y;
	m_Charlie0.Init(hdc, "player0.bmp", "player0.bmp", postmp);
	m_Charlie1.Init(hdc, "player1.bmp", "player1.bmp", postmp);
	m_Charlie2.Init(hdc, "player2.bmp", "player2.bmp", postmp);
	m_CharlieDie.Init(hdc, "die.bmp", postmp);
	m_ObjectArea = { postmp.x , postmp.y, postmp.x + m_Charlie0.BitmapSizeOutput().cx , postmp.y + m_Charlie0.BitmapSizeOutput().cy };

}

void Charlie::CharlieDraw(HDC hdc)
{
	POINT pointtmp;
	pointtmp.x = NULL;
	pointtmp.y = NULL;

	switch (m_CharacterMotion)
	{
	case CHARACTER_MOTION_MOVE_1:
		m_Charlie0.Draw(hdc, NULL);
		pointtmp = m_Charlie0.BitmapPointOutput();
		break;
	case CHARACTER_MOTION_MOVE_2:
		m_Charlie1.Draw(hdc, NULL);
		pointtmp = m_Charlie1.BitmapPointOutput();
		break;
	case CHARACTER_MOTION_MOVE_END:
		m_Charlie2.Draw(hdc, NULL);
		pointtmp = m_Charlie2.BitmapPointOutput();
		break;
	case CHARACTER_MOTION_JUMP:
		m_Charlie2.Draw(hdc, NULL);
		pointtmp = m_Charlie2.BitmapPointOutput();
		break;
	case CHARACTER_MOTION_DEAD:
		m_CharlieDie.Draw(hdc);
		pointtmp = m_CharlieDie.BitmapPointOutput();
		break;
	}
	m_ObjectArea = { pointtmp.x , pointtmp.y, pointtmp.x +m_Charlie0.BitmapSizeOutput().cx , pointtmp.y+m_Charlie0.BitmapSizeOutput().cy };
}

void Charlie::CharlieMove(int keyflag)
{
	switch (m_CharacterMotion)
	{
	case CHARACTER_MOTION_MOVE_1:
		m_CharacterMotion = CHARACTER_MOTION_MOVE_2;
		break;
	case CHARACTER_MOTION_MOVE_2:
		m_CharacterMotion = CHARACTER_MOTION_MOVE_END;
		break;
	case CHARACTER_MOTION_MOVE_END:
		m_CharacterMotion = CHARACTER_MOTION_MOVE_1;
		break;
	}

}

bool Charlie::CharlieJump()
{
	int misec;
	POINT pointtmp;

	TimeManager::GetInstace()->NowTimeSet(m_JumpTimeInfo.PassTime);
	misec = TimeManager::GetInstace()->InvertToMisec(TimeManager::GetInstace()->TimeMinus(m_JumpTimeInfo.StartTime, m_JumpTimeInfo.PassTime)); //점프키 누른 시간과 지금 시간을 빼서 misec 단위로 변환

	//체공시간이 지났거나 2초가 지났으면 강제로 점프 종료
	if (TimeManager::GetInstace()->TimeOverCheck(m_JumpTimeInfo.EndTime, m_JumpTimeInfo.PassTime) == true || misec >= JUMPINGTIMESECOND * 1000) 
	{
		pointtmp.x = CHARACTER_X_POSDEFAULT + START_POS_X;
		pointtmp.y = CHARACTER_Y_POSDEFAULT + START_POS_Y;
		m_Charlie2.PosChange(pointtmp);
		m_CharacterMotion = CHARACTER_MOTION_MOVE_1;
		return false;
	} // 점프 끝 

	float dgree = (180 * (float)misec) / (JUMPINGTIMESECOND * 1000); //JUMPINGTIMESECOND(체공시간)기준으로 misec를 각도로 변환 
	float Radian = TimeManager::GetInstace()->DegreeToRadian(dgree); // 라디안으로 변환
	
	pointtmp.x = CHARACTER_X_POSDEFAULT + START_POS_X;
	pointtmp.y = (CHARACTER_Y_POSDEFAULT + START_POS_Y) + (JUMP_DISTANCE * -sin(Radian));
	if (pointtmp.y > CHARACTER_Y_POSDEFAULT + START_POS_Y) //점프시 캐릭터 위치보다 내려가지 않게하는 예외조건
		pointtmp.y = CHARACTER_Y_POSDEFAULT + START_POS_Y;

	m_Charlie2.PosChange(pointtmp);
	return true;
}

void Charlie::JumpStartTimeSet()
{
	TimeManager::GetInstace()->NowTimeSet(m_JumpTimeInfo.StartTime);
	m_JumpTimeInfo.EndTime = m_JumpTimeInfo.StartTime;
	TimeManager::GetInstace()->Timeadd(m_JumpTimeInfo.EndTime, NULL, NULL, JUMPINGTIMESECOND, NULL);
	CharlieStateChange(CHARACTER_STATE_JUMP);
}

void Charlie::CharlieStateChange(CHARACTER_STATE state)
{
	switch (state)
	{
	case CHARACTER_STATE_JUMP:
		m_CharacterMotion = CHARACTER_MOTION_JUMP;
		break;
	case CHARACTER_STATE_DEAD:
		
		if (m_CharacterMotion == CHARACTER_MOTION_JUMP)
			m_CharlieDie.PosChange(m_Charlie2.BitmapPointOutput());
		m_CharacterMotion = CHARACTER_MOTION_DEAD;
		break;
	default:
		break;
	}

}

void Charlie::CharlieReset()
{
	m_CharacterMotion = CHARACTER_MOTION_MOVE_1;
	POINT postmp;
	postmp.x = CHARACTER_X_POSDEFAULT + START_POS_X;
	postmp.y = CHARACTER_Y_POSDEFAULT + START_POS_Y;
	m_Charlie0.PosChange(postmp);
	m_Charlie1.PosChange(postmp);
	m_Charlie2.PosChange(postmp);
	m_CharlieDie.PosChange(postmp);
	m_ObjectArea = { postmp.x , postmp.y, postmp.x + m_Charlie0.BitmapSizeOutput().cx , postmp.y + m_Charlie0.BitmapSizeOutput().cy };
}

Charlie::~Charlie()
{
	delete TimeManager::GetInstace();
}
