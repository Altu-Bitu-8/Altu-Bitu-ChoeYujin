#include<iostream>
#include<vector>

using namespace std;

vector<int>family[101]; //n입력 최대값이 100
bool visited[101]; //방문 체크

//촌수를 리턴해주는 함수
//x가 부모, y가 자식 두 노드는 cnt개로 연결되어 있다는 점을 이용
//dfs로 탐색 ->x의 자식 값 중 하나가 x가 되어 재귀호출
int dfs(int x, int y, int cnt){
    if(x == y) return cnt; //x==y 촌수 세는 모든 과정에 도달->리턴
    
    visited[x] = true;//x 방문 체크
    
    for(int i=0; i<family[x].size(); i++){//x의 자식들을 탐색
        int next = family[x][i]; //다음 탐색 차례는 x의 자식
        
        if(!visited[next]){
            int res = dfs(next, y, cnt+1);//부모자식 관계를 하나 지나쳤으므로 재귀 시에는 cnt+1
            if(res != -1){//y까지 도달하지 못할 경우 -1반환
                return res;//따라서 재귀호출 끝에 올바르게 x==y에 도달한 경우에만 반환
            }
        }
    }
    
    return -1;
}



int main(){
    int n, m, x, y;
    cin >>n;
    cin >> x >> y;
    cin >> m;
    
    //부모자식관계 입력->family에 저장
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        family[a].push_back(b);
        family[b].push_back(a);
    }
    
    cout << dfs(x, y, 0);
    
    return 0;
}