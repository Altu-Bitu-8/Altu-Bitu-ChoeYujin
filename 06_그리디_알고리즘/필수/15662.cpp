#include<iostream>
#include<vector>
#include<deque>

using namespace std;

//1-1. 회전한 방향에 따라 큐값 수정
//1-2. 회전한 이후 전파가 이루어지는지 확인 후 vector v에 저장
void rotateWheel(deque<char>&wheel, int d){
    if(d == -1){//반시계방향이라면: 0번이 맨 뒤로감
        char temp = wheel.front();
        wheel.pop_front();
        wheel.push_back(temp);
    }
    else if(d == 1){// 시계방향이라면: 맨뒤가 앞으로 들어감
        char temp = wheel.back();
        wheel.pop_back();
        wheel.push_front(temp);
        
    }
}




int main(){
    //입력1
    int t;
    cin >> t;
    vector<deque<char>>wheel(t);//행: t인 2차원 벡터 선언
    
    for(int i=0; i<t; i++){
       string s;
       cin >> s;
       for(char c : s){
           wheel[i].push_back(c);
       }
    }
    
    //입력2
    int k; //회전횟수
    cin >> k;
    
    
    for(int i=0; i<k; i++){
        int num, dir;
        cin >> num>> dir;
        
        num--; //입력되는 번호와 index 차이의 1빼줌
        vector<int>rotate_dir(t); //회전할 방향을 저장. 1시계방향, -1반시계, 0회전x
        rotate_dir[num]=dir;
        
        //num에서 오른쪽 방향으로로
        for(int j =num; j<wheel.size()-1; j++){
            if(wheel[j][2] != wheel[j+1][6]){//톱니 극이 다르면
                rotate_dir[j+1] = -rotate_dir[j]; //그 다음 바퀴는 반대방향으로 회전
            }
            else{//톱니 두 극이 같다면
                break; //더이상 전파가 안 일어나므로 for문 탈출출
            }
        }
        
        //num에서 왼쪽 방향으로
        for(int j = num; j>0; j--){
            if(wheel[j][6] != wheel[j-1][2]){//톱니 극이 다르면
                rotate_dir[j-1] = -rotate_dir[j]; // 그 다음 바퀴는 반대방향으로 회전
            }
            else{
                break;
            }
        }
        
        //회전할 방향+회전할지 여부를 rotate_dir에 기록했으므로 실제 회전을 함
        for(int j=0; j<wheel.size(); j++){
            if(rotate_dir[j] != 0){
                rotateWheel(wheel[j], rotate_dir[j]);
            }
        }
    }
    
    //12시 방향=각 deque의 front == N인 개수 세기
    int cnt=0;
    for(int i=0; i<t; i++){
        if(wheel[i].front() == '1'){
            cnt++;
        }
    }
    
    //출력
    cout << cnt;
    
    return 0;
}