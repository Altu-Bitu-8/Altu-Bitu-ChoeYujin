// 백준 1240번 
//노드 정보를 벡터에 저장후 dfs로 거리를 탐색하는 구조조
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 트리를 표현하는 인접 리스트 (노드 번호 → 연결된 노드 목록)
map<int, vector<int>> tree;

// 각 간선의 가중치를 저장하는 2차원 벡터
vector<vector<int>> weight;

// 현재 노드 cur에서 시작해 dest까지 가는 경로의 거리 합을 구하는 DFS 함수
int dfs(int cur, int dest, int sum, vector<bool>& visited) {
    // 목적지에 도달했으면 누적합 반환
    if (cur == dest) return sum;

    visited[cur] = true; // 현재 노드 방문 처리

    // 인접한 노드들에 대해 순회
    for (int next : tree[cur]) {
        if (!visited[next]) {
            // 다음 노드로 이동하면서 가중치 합산
            int res = dfs(next, dest, sum + weight[cur][next], visited);//합산한 가중치를 인자로 받고 재귀호출
            if (res != -1) return res; // 경로를 찾았으면 바로 반환
        }
    }

    return -1; // 경로를 찾지 못했을 경우 (트리 구조라서 사실상 항상 경로 있음)
}

int main() {
    //입출력속도 향상
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; // 노드 개수와 쿼리 개수 입력

    // 간선의 가중치를 저장할 n+1 크기의 2차원 배열 생성 (1번 노드부터 사용)
    weight.assign(n + 1, vector<int>(n + 1));

    // 간선 정보 입력 (트리는 n-1개의 간선으로 구성됨)
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;//트리상에 연결된 두 점(u, v)과 두 점 사이의 거리(w)
        cin >> u >> v >> w;

        // 각 노드의 간선 연결
        tree[u].push_back(v);//노드는 쌍방향 연결이므로 u에도 v를
        tree[v].push_back(u);//v에도 u를 넣어줌줌

        // 가중치 저장
        weight[u][v] = w;//쌍방향 연결이므로 가중치 또한 uv vu 둘 다에 저장
        weight[v][u] = w;
    }

    //두 노드 사이의 거리 계산
    while (m--) {//m 알고 싶은 노드 쌍의 개수
        int u, v; // 거리를 알고 싶은 노드쌍을 입력 받음음
        cin >> u >> v;

        vector<bool> visited(n + 1, false);//방문체크 할 벡터 생성 후 fasle로 초기화화

        cout << dfs(u, v, 0, visited) << '\n';
    }

    return 0;
}
