#include <iostream>

using namespace std;

void calculator(string &cal, int &x, long long &test){
    
    if(cal == "add"){
        if(~(test & (1<<x))){//x번째 자리가 !(0&1)이라면
            test |= (1<<x); //x번째 자리를 1로
        }
    }
    else if(cal == "remove"){
        if(test & (1<<x)){//x번째 자리가 1&1 이라면
            test &= ~(1<<x); //x번째 자리를 0으로
        }
        
    }
    else if(cal == "check"){
        if(test & (1<<x)){
            cout << 1 << '\n';
        }else{
            cout << 0 <<'\n';
        }
        
    }
    else if(cal == "toggle"){
        if(test & (1<<x)){
            test &= ~(1<<x); //원소가 있다면 0으로
        }
        else{
            test |= (1<<x); //원소가 없다면 1로
        }
    }
    else if(cal == "all"){//삭제 후 1~20까지 원소 추가
        test=0; //다 0으로 초기화
        for(int i=1; i<=20; i++){
            test |= (1<<i);
        }
    }
    else if(cal == "empty"){
        test=0;
    }
}



int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m;
    cin>>m;
    
    long long test=0; //비트연산, 20자리가 필요하므로 long long
    
    while (m--){
        string cal; int x;
        cin >> cal;
        
        if(cal != "all" && cal != "empty"){
            cin >> x;
        }
        
        calculator(cal, x, test);
        
    }
    
    return 0;
}