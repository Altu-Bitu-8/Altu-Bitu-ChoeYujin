#include <iostream>
#include <vector>

using namespace std;

int twoPointer(vector<int> &sushi, int n, int k, int d, int c){
    vector<int>cnt(d+1, 0);//1~d 이므로 d+1, 초밥의 종류와 개수를 저장하는 벡터터
    int kind=0;//종류 수를 저장하는 변수수
    int result =0;
    for(int i=0; i <k; i++){
        if(cnt[sushi[i]] == 0){//새로운 종류의 초밥이면
            kind++;//kind를 +1
        }
        cnt[sushi[i]]++;
    }
    
    for(int i=0; i<n; i++){
        int temp = kind;
        if(cnt[c] == 0){//쿠폰으로 받은 초밥이 중복x일 경우우
            temp++; 
        }
        result = max(result, temp);
        
        if(--cnt[sushi[i]] == 0){//앞의 접시가 빠짐짐
            kind--;//kind -1
        }
        int next = sushi[(i + k) % n];//앞의 접시가 하나 빠지면서 뒤의 접시 추가
        if(cnt[next]++ == 0){
            kind++;//종류 중복이 아니라면 kind+1
        }
    }
    
    return result;
    
}

int main()
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    
    vector<int>sushi(n);//컨테이너벨트의 초밥 정보를 저장할 벡터
    
    for(int i=0; i<n; i++){
        cin >> sushi[i];
    }
    
    
    cout << twoPointer(sushi, n, k, d, c);
    
    return 0;
}