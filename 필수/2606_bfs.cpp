/*2606번의 경우 dfs와 bfs 두가지 버전으로 풀었습니다.
개인적인 공부용으로 두가지 버전으로 작성한 것이니 코드리뷰는 한 가지만 해주셔도 괜찮습니다. */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>computer[101];
bool visited[101]; //컴퓨터는 100이하의 정수

int find(){
    int cnt = 0;//감염된 컴퓨터 개수 카운트
    queue<int>virus;//bfs 탐색을 위한 큐
    visited[1] = true; //1번 컴퓨터는 바이러스 감염->방문체크
    virus.push(1);//큐에도 넣어줌
    
    while (!virus.empty()){
        int now= virus.front();
        virus.pop();
        
        for(int i=0; i<computer[now].size(); i++){
            int next = computer[now][i];
            if(!visited[next]){
                cnt++;//감염된 개수+1
                visited[next] = true;//방문체크
                virus.push(next);//큐에 추가해 다음 차례에 탐색될 수 있도록
            }
        }
    }
    
    return cnt;
}


int main(){
    int n, m;
    cin>> n;
    cin >>m;
    
    //연결된 컴퓨터 입력
    for(int i=0; i<m; i++){
        int a, b; 
        cin >> a >> b;
        computer[a].push_back(b);
        computer[b].push_back(a);
    }
    
    cout << find();
    
    return 0;
}