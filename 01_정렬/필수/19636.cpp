#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int w0, i0, t;//시작체중, 기초대사량, 역치
	int d, i, a;//기간, 일일에너지섭취량, 일일활동대사량
	
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a; //입력

	int m = i0;//변화x 기초대사량
	int m2 = i0;//변화o 기초대사량

	int w1 = w0; //기초대사량 변화 고려x 체중
	int w2 = w0; //기초대사량 변화 고려 o 체중
	

	for (int j = 0; j < d; j++) {
		w1 += i - (m + a);
		w2 += i - (m2 + a);

		if (abs(i - (m2 + a)) > t)
			m2 += floor((i - (m2 + a)) / 2.0); 
		//절대값이 t보다 크다면 기초대사량 m2 변화
	}
	//첫번째줄-변화x 출력
	if (w1 <= 0)//체중이 0이하면 사망
		cout << "Danger Diet\n";
	else
		cout << w1 <<" "<< m << '\n'; 

	//두번째줄-변화o 출력
	if (w2 <= 0 || m2 <= 0)//체중이0이하 or 기초대사량 0이하 사망
		cout << "Danger Diet";
	else {
		cout << w2 << " " << m2 << " ";
		if (m > m2)//변화한 기초대사량이 기존 기초대사량보다 작다면 요요
			cout << "YOYO";
		else
			cout << "NO";
	}
}
