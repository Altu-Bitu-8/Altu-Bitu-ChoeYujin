#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char a){
    if (a=='*' || a == '/'){
        return 2;
    }
    else if (a=='-' || a=='+'){
        return 1;
    }
    return 0;
}

int main(){
    
    string str;
    stack <char> cal;
    string ans;
    
    cin >> str;
    
    for (int i=0; i<str.size(); i++){
        if(str[i] >= 'A' && str[i]<='Z'){//문자열이 들어온다면 그대로 출력력
            ans+=str[i];
        }
        
        else if(str[i] == '('){//여는 괄호가 들어온다면 우선순위 조정을 위해 check
            cal.push(str[i]);
        }
        
        else if(str[i] == '*' || str[i] == '/'){//우선순위 높은 연산자는 push
            while(!cal.empty() && priority(cal.top())>= priority(str[i])){//top과 우선순위가 같을 경우 pop후 push
                ans+=cal.top();
                cal.pop();
            }
            cal.push(str[i]);
        }
        
        else if(str[i] == '+' || str[i] == '-'){//우선순위 낮은 연산자는
            while(!cal.empty() && priority(cal.top())>=priority(str[i])){//push 전에 우선순위 높은 연산자를 다 pop
                ans+=cal.top();
                cal.pop();
            }
            cal.push(str[i]);//그 이후에 push
        }
        else if(str[i] == ')'){//닫는괄호는 
            while(!cal.empty() && cal.top() != '('){ //괄호 안에 들어가는 연산자를 다 pop
                ans += cal.top();
                cal.pop();
            }
            cal.pop();//여는 괄호를 스택에서 제거
        }
    }
    
    while(!cal.empty()){//남은 연산자가 없을 때까지 pop
        ans+=cal.top();
        cal.pop();
    }
    
    cout << ans;
    
    return 0;
}