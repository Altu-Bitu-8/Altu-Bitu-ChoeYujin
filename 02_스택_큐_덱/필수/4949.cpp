#include<stack>
#include<iostream>
#include<string>

using namespace std;
//여는 괄호가 들어올 경우 stack에 push
/* 닫는괄호가 들어올 경우
1. stack이 비어 있지 않은지(=앞서 여는 괄호가 먼저 나왔는지)확인
2. 가장 최근에 push된 괄호와 맞는 쌍인지 확인 */

bool balance(string &str){
    stack<char>check;
    
    for(int i=0; i<str.size(); i++){
        if (str[i]=='[' || str[i]=='('){
            check.push(str[i]);
        }
        else if(str[i]==']'){
            if (check.empty() || check.top() != '[') return false; 
            check.pop();
        }
        else if (str[i] == ')'){
            if (check.empty() || check.top() != '(') return false;
            check.pop();
        }
    }
   return check.empty(); //균형이 맞기 위해서는 스택이 비어있어야함
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0); //버퍼에 저장했다가 한번에 출력하기 위해
    
    while(true){
        string str;
        getline(cin, str); //공백포함이므로 cin이 아닌 getline을 이용
        
        if(str == ".") break; //'.'이 들어오면 루프 탈출
        
        cout << (balance(str) ? "yes" : "no")<<'\n';
        //balance함수가 true or false를 반환
    }
    
    return 0;
}