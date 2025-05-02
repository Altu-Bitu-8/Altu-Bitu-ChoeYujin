#include<iostream>
#include<vector>

using namespace std;

int min_cost = 10000000;
int cost[10][10]; //도시간 이동비용을 저장할 배열

void cal(int start, int current, int idx, int sum, int &n, vector<bool>&visit){
    if(idx == n){//n번째 도시일 떄
        if(cost[current][start] != 0){//처음 위치로 돌아올 수 있는지 체크
            min_cost = min(sum+cost[current][start], min_cost);
        }
        return;
    }
    
    for(int next=0; next<n; next++){
        if(cost[current][next] != 0 && visit[next] == false){//갈 수있는 길이 있음&&아직방문x
            visit[next] = true;//방문체크
            cal(start, next, idx+1, sum+cost[current][next], n, visit);
            visit[next] = false; //방문체크 해제
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<bool>visit(n, false);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> cost[i][j];
        }
    }
    
    //외판원은 모든 도시를 방문하므로 어떤 도시에서 시작해도 답은 동일
    //편의상 0번도시에서 시작
    visit[0] = true;
    cal(0, 0, 1, 0, n, visit);
    visit[0] = false;
    
    cout << min_cost;
    
    return 0;
}