#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){
	string s;
	cin >> s;

	set<string> block; //잘린 문자열을 보관할 자료구조, set: 중복x

	for(int i=0; i<s.size(); i++){//서브문자열 시작 인덱스
	    for(int j=1; j<=s.size(); j++){//서브 문자열 길이이
	        block.insert(s.substr(i, j));
	    }
	}

	cout << block.size(); //set의 원소 수 반환

}