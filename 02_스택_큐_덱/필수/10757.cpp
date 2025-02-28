#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//큰 두 정수의 자리수를 0으로 맞춰주는 함수수
void fillZero(string &A, string &B){
    if (A.size() < B.size()) {
		swap(A, B); // 편의상 A가 항상 더 크도록 함
	}
	
	//B에 '0'을 채워줌
	if (A.size() != B.size()) {
		B.append(A.size()-B.size(), '0');
	}
}

//큰 두 정수를 합하는 함함수
void intPlus(string &A, string &B, stack<int>&result){
    int sum=0; int carry=0;
    
    for(int i=0; i<A.size(); i++){
        int a=A[i]-'0'; int b=B[i]-'0';
        sum=a+b+carry;
        carry = 0;//전 자리에서 받아온값을 초기화화
        
        //sum이 10이상일 경경우
        if(sum>=10){
            carry=sum/10;
            sum = sum%10;
        }
        
        //합을 저장
        result.push(sum);
    }
    
    //합계가 자리수+1이 되는 경우
    if(carry !=0){
        result.push(carry);
    }
}

int main() {

	string A, B; //정수형이 받을 수 있는 범위를 초과하므로 문자열로 입력 받음

	cin >> A >> B; //입력받음

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end()); // 계산을 위해 문자열을 뒤집음(일의자리부터 계산함으로)

    fillZero(A, B);

	stack <int> result; // 결과값을 저장할 공간

	intPlus(A, B, result);
    
    //출력력
    while(!result.empty()){
        cout << result.top();
        result.pop();
    }
}