#include <iostream>
using namespace std;

int main(){
	
	// rand() 은 항상 같은 값을 출력하기에 
	// srand() 함수를 사용하여 시드값을 넣어서 계속 새로운 값을 출력할수있음

	// srand()에 시드값은 유동적으로 변경되는 time()함수를 넣음
	srand(time(0));
/*	int value = 1 + (rand() % 3)*/ ; // 0 ~ 32767
	// 1, 2, 3 값을 위해서는 % 3을 씀 그러면 나머지가 0,1,2 가 나옴 여기에 +1을 해주면 1,2,3 이 가능함
	
	int user;
	int com;
	int select;

	char nickname[20];

	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;
	
	int score = 0;

	int win = 0;
	int total = 0;

	int result;


	

	cout << "닉네임을 설정해주세요 : ";
	cin >> nickname;

	cout << nickname << " 님 반갑습니다!" << endl;

	while (true) {
		com = 1 + (rand() % 3);

		cout << "\n가위(1) 바위(2) 보(3) 골라주세요!" << endl;
		cout << "\n> ";
		cin >> user;

		if (total == 0) {
			cout << "현재 승률 : 없음" << endl;
		}
		else {
			int winPercentage = ( win * 100 )/ total;
			cout << "현재 승률 : " << winPercentage << endl;
		}
		

		if (user == SCISSORS) {
			cout << "\n> ";
			if (com == SCISSORS) {
				cout << "가위(" << nickname << ") vs 가위(컴퓨터) 무승부 입니다." << endl;
			}else if (com == ROCK) {
				cout << "가위(" << nickname << ") vs 바위(컴퓨터) 당신이 졌습니다." << endl;
				total++;
			}else {
				cout << "가위(" << nickname << ") vs 보(컴퓨터) 당신이 이겼습니다." << endl;
				total++;
				win++;
				
			}
		}else if (user == ROCK) {
			cout << "\n> ";
			if (com == SCISSORS) {
				cout << "바위(" << nickname << ") vs 가위(컴퓨터) 당신이 이겼습니다." << endl;
				total++;
				win++;
			}else if (com == 2) {
				cout << "바위(" << nickname << ") vs 바위(컴퓨터) 무승부 입니다." << endl;
			}else {
				cout << "바위(" << nickname << ") vs 보(컴퓨터) 당신이 졌습니다." << endl;
				total++;
			}
		}else if (user == PAPER) {
			cout << "\n> ";
			if (com == SCISSORS) {
				cout << "보(" << nickname << ") vs 가위(컴퓨터) 당신이 졌습니다." << endl;
				total++;
			}else if (com == ROCK) {
				cout << "보(" << nickname << ") vs 바위(컴퓨터) 당신이 이겼습니다." << endl;
				total++;
				win++;
			}else {
				cout << "보(" << nickname << ") vs 보(컴퓨터) 무승부 입니다." << endl;
			}
		}else {
			cout << "\n오류 발생!\n";
			break;
		}

		/*cout << "\n처음으로 돌아간다.\n" << "(1)예 (2)아니오" << endl;
		cin >> select;

		if (select == 1) {
			continue;
		}else if (select == 2) {
			break;
		}else {
			cout << "오류 발생!\n";
			break;
		}*/
		

	}


   
}
