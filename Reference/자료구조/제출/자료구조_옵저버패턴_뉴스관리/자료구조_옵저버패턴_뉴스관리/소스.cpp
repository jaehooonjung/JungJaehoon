#include"Data.h"

void main()
{
	int Select;
	string strTmp;

	while (1)
	{
		system("cls");
		cout << "===뉴스===" << endl;
		cout << " 1. 고객등록" << endl;
		cout << " 2. News 전송" << endl;
		cout << " 3. News 업데이트" << endl;
		cout << " 4. News 시청" << endl;
		cout << " 5. 종료" << endl;
		cout << "선택 : ";
		cin >> Select;

		switch (Select)
		{
		case 1:
			cout << "고객님의 이름을 입력하세요 : ";
			cin >> strTmp;
			Data::GetInstace()->AddObserver(strTmp);
			break;
		case 2:
			Data::GetInstace()->NotifyObserver();
			break;
		case 3:
			cout << "기사내용을 입력하세요 : ";
			cin.ignore();
			getline (cin, strTmp);
			Data::GetInstace()->SetData(strTmp);
			break;
		case 4:
			Data::GetInstace()->Print();
			system("pause");
			break;
		case 5:
			delete Data::GetInstace();
			return;
		}
	}



}