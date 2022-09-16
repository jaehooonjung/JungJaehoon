프로젝트명 : 체스 게임
프로젝트 개요 : 마우스를 통해 진행되는 체스 게임으로 1~2인에서 즐길 수 있다. 
개발 인원 : 1인 개발
기술 스택 : C++, winapi
업무 기간 : 2019.02 ~ 2019.03 (약 1개월) 
	Class
Block
-	체스 게임판의 각각의 공간정보를 저장한다.
BlockManager
-	체스 게임판을 그려주는 클래스
ChessGame
-	체스게임의 전반적인 진행을 담당하며 마우스 클릭 여부 및 누구의 차례인지 저장된다.
Chesspiece
-	체스말의 정보를 저장한다.
ChesspieceManager 
-	체스말의 이동,생성,삭제 등을 관리하는 클래스 
	헤더파일
Mecro.h
-	각종 상수, enum, include문을 선언한다.
	소스파일 
소스.cpp
-	게임 실행에 필요한 init 함수들과 메인함수를 실행한다.

