#include"Std_manager.h"

void main() 
{
	int sel;
	while (true)
	{
		cout << "=========================" << endl;
		cout << "   1.학생 등록" << endl;
		cout << "   2.전체 학생정보 출력" << endl;
		cout << "   3.학생 번호 검색" << endl;
		cout << "   4.학생 이름 검색" << endl;
		cout << "   5.등급별 출력" << endl;
		cout << "   0.종료" << endl;
		cout << "=========================" << endl;
		cin >> sel;
		switch (sel) {
		case 1:
			Std_manager::GetInstace()->setStudent();
			break;
		case 2:
			Std_manager::GetInstace()->showStudent();
			break;
		case 3:
			Std_manager::GetInstace()->findNumber();
			break;
		case 4:
			Std_manager::GetInstace()->findname();
			break;
		case 5:
			Std_manager::GetInstace()->findClass();
			break;
		case 0:
			delete Std_manager::GetInstace();
			return;

		
		default:cout << "잘못 입력 " << endl;
		}
		system("pause"); system("cls");
	}

}