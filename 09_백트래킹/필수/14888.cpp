#include <iostream>
#include <vector>

using namespace std;

int ans1 = -1000000000;
int ans2 = 1000000000;

void cal(int n, int idx, int result, vector<int>&number, vector<int>&op){
    if(idx == n){
        ans1 = max(ans1, result);//최대값 갱신
        ans2 = min(ans2, result);//최소값 갱신신
        return;
    }
    
    for(int i=0; i<4; i++){
        if(op[i] >0){
            op[i]--; //연산자를 사용하므로 해당 연산자 -1
            
            if(i == 0){// +
                cal(n, idx+1, (result+number[idx]), number, op);
            }
            else if(i == 1){//-
                cal(n, idx+1, (result-number[idx]), number, op);
            }
            else if(i == 2){// *
                cal(n, idx+1, (result*number[idx]), number, op);
            }
            else{ // /
                cal(n, idx+1, (result/number[idx]), number, op);
            }
            
            op[i]++; //다른 경우의 수를 탐색하므로 연산자를 +1해줘서 원래 개수대로 복구
        }
    }
    
    return;
   
    
}

int main()
{
    //input
    int n;
    cin >> n;
    vector<int>number(n);
    vector<int>op(4, -1); //연산자
    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        number[i] = a;
    }
    
    for(int i=0; i<4; i++){
        int a;
        cin >> a;
        op[i] = a;
    }
    
    //백트래킹으로 연산
    cal(n, 1, number[0], number,op);
    
    //print
    cout << ans1 << '\n';
    cout << ans2;

    return 0;
}