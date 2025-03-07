#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void sum(string a, int &asum){//문자열의 숫자의 합을 반환하는 함수
	for(int i=0; i<a.size(); i++){
		if('0'<=a[i] && a[i]<='9'){//문자가 숫자일 떄 합을 더함
			asum += int(a[i])-48;
		}
	}
}

bool cmp(string a, string b) {
	int alength = a.size();
	int blength = b.size();
	int asum = 0;
	int bsum = 0;//초기화

	if (a.size() != b.size()) //길이 순서대로 정렬
		return a.size() < b.size();

	sum(a, asum);//앞서 정의한 함수를 이용해 문자열 a,b 각각의 합을 구함
	sum(b, bsum);

	if (asum != bsum) 
		return asum < bsum;//길이가 같다면 숫자들의 합으로 정렬

	return a < b; // 합이 같다면 사전순으로 정렬

}

int main()
{
	int n;
	cin >> n;
	string s[50]; //시리얼 최대 길이가 50이므로

	for (int i = 0; i < n; i++) {
		cin >> s[i]; //시리얼을 입력받음
	}

	sort(s, s + n, cmp); //상단에서 정한 규칙대로 정렬
	
	for (int i = 0; i < n; i++)
		cout << s[i] << '\n'; //정렬한 것을 출력

	return 0;
}