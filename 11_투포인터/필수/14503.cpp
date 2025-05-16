#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;//청소하는 칸의 개수수
vector<vector<int>> board;
vector<vector<bool>> visited;
int n, m;

void clean(int r, int c, int d) {
    //현재칸이 청소되어 있지 않다면 청소
    if (!visited[r][c]) {
        visited[r][c] = true;
        cnt++;
    }

    int next = d;

    //4방향을 반복문을 돌며 탐색
    for (int i = 0; i < 4; i++) {
        next = (next + 3) % 4; // 반시계로 회전하며 방향 탐색
        int nr = r, nc = c;

        if (next == 0) nr = r - 1;      // 북
        else if (next == 1) nc = c + 1; // 동
        else if (next == 2) nr = r + 1; // 남
        else if (next == 3) nc = c - 1; // 서

        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {//범위 벗어나는지 체크
            if (board[nr][nc] == 0 && !visited[nr][nc]) {//방문한적 없음 && 벽이 없음음
                clean(nr, nc, next);//새 방향을 재귀로 호출하며 탐색색
                return;
            }
        }
    }

    //4방향 중에 청소해야할 곳이 없을 때: 후진
    int br = r, bc = c;
    if (d == 0) br = r + 1;
    else if (d == 1) bc = c - 1;
    else if (d == 2) br = r - 1;
    else if (d == 3) bc = c + 1;

    if (br >= 0 && br < n && bc >= 0 && bc < m && board[br][bc] == 0) {
        clean(br, bc, d);
    }
}

int main() {
    //input
    cin >> n >> m;

    int r, c, d;
    cin >> r >> c >> d;

    board.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));//방문체크용-기본값을 false로 설정

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> board[i][j];

    clean(r, c, d);

    cout << cnt;
    return 0;
}
