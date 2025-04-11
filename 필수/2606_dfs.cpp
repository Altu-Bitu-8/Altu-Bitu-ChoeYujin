/*2606번의 경우 dfs와 bfs 두가지 버전으로 풀었습니다.
개인적인 공부용으로 두가지 버전으로 작성한 것이니 코드리뷰는 한 가지만 해주셔도 괜찮습니다. */

#include <iostream>
#include <vector>

using namespace std;

vector<int>computer[101];
bool visited[101]; //컴퓨터는 100이하의 정수
int cnt=0; //재귀호출을 해아하므로 전역변수로 선언

void find_dfs(int a){//인자a는 탐색할 컴퓨터 번호-bfs와 달리 재귀호출을 위해 1로 고정하지 않음
    visited[a] = true; //방문체크
    
    for(int i=0; i<computer[a].size(); i++){
        int next = computer[a][i];
        if(!visited[next]){//방문하지 않았다면
            cnt++;//감염된 컴퓨터 수+1
            find_dfs(next);//재귀
        }
    }
    
}

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        computer[a].push_back(b);
        computer[b].push_back(a);
    }
    
    
    find_dfs(1); //1번컴퓨터가 제일 먼저 감염
    cout << cnt;
    
    return 0;
}