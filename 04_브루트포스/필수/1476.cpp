#include<iostream>

using namespace std;

const int MAX = 10000;//int 범위를 벗어나지 않는 적당히 큰 정수

int year(int &e, int &s, int &m){
    int ans=-1;//답은 무조건 양수이므로 -1로 초기화
    
    for(int i=0; i< MAX; i++){
        ans = i * 15 + e;
        
        //28, 19의 배수일 경우를 생각해야하므로 s, e가 아니라 각 수로 나눈 나머지와 비교
        if((ans % 28 == (s % 28)) && (ans % 19 == (m % 19))){
            break;
        }
        else{
            continue;
        }
    }
    return ans;
}


int main(){
    
    int e, s, m;
    cin >> e >> s >> m;
    
    cout << year(e,s,m);
    
    
    return 0;
}