﻿#include <iostream>
using namespace std;

int main(){

	//cout -> 콘솔 아웃 
	// << <- 밀어넣어 주세요 ,모니터에 출력해주세요


	

	// endl << 한줄을 띄는 명령어




	// 별찍기)
	// 유저들이 어떤 정수를 입력하면
	// n*n 개의 별을 찍었으면 좋겠어요!

	// 4를 입력 받으면 
	/*
		****
		****
		****
		****
	*/

	int input1;
	cout << "정수 입력 : ";
	cin >> input1;


	for (int i=0; i < input1; i++) {
		for (int j=0; j <= input1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	// 별찍기 2)
	// n*n개의 별을 찍으니까 넘 심심하다.
	// 1개부터 시작해서 순차적으로 줄마다 증가하게 수정해주세요!

	int input2;
	cout << "정수 입력 : ";
	cin >> input2;


	for (int i = 0; i < input2; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	// 별찍기 3)
	// 모양이 많이 개선되긴 했는데
	// n개부터 시작해서 줄마다 1개씩 줄어드는 형태로

	int input3;
	cout << "정수 입력 : ";
	cin >> input3;


	for (int i = 0; i < input3; i++) {
		for (int j = input3; j > i; j--) {
			cout << "*";
		}
		cout << "\n";
	}

	// 구구단)
	// 2*1 =2
	// 2단부터 9단까지 구구단을 출력해주세요

	cout << endl;

	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int result = i * j;

			cout << i << " * " << j << " = " << result << endl;
		}
		cout << "\n";
	}

}
