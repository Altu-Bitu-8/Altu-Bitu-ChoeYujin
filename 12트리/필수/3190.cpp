#include <iostream>
#include <vector>
#include <deque>

using namespace std;


vector<vector<int>> board; //초기값0, 사과1, 뱀2
deque<pair<int, int>> snake;
vector<pair<int, char>> cmd;

int dx[4] = {0, 1, 0, -1}; // 북 동 남 서
int dy[4] = {-1, 0, 1, 0};

int turn(char c, int x) {
    if (c == 'L'){
        return (x + 3) % 4;
    }
    else{//c == D
         return (x + 1) % 4;
    }
}

int simulate(int n, int l) {
    int x = 1, y = 1, d = 1, time = 0, idx = 0;
    snake.push_back({y, x});
    board[y][x] = 2; // 뱀이 있는 곳

    while (true) {
        time++;
        int nx = x + dx[d];
        int ny = y + dy[d];

        // 범위 벗어나거나 자기 몸에 부딪히면 종료
        if (nx < 1 || ny < 1 || nx > n || ny > n || board[ny][nx] == 2){
            break;
        }

        if (board[ny][nx] == 1) { // 사과 있으면
            board[ny][nx] = 2; //몸의 길이가 늘어남
            snake.push_front({ny, nx});
        }
        
        else { // 빈 칸이면 길이 줄이기
            board[ny][nx] = 2;//뱀의 몸 위치 체크크
            snake.push_front({ny, nx});
            auto tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }

        // 다음 이동
        y = ny;
        x = nx;

        // 방향 전환 시간 확인
        if (idx < l && time == cmd[idx].first) {
            d = turn(cmd[idx].second, d);
            idx++;
        }
    }

    return time;
}

int main() {
    //사과의 위치 입력력
    int n, k, l;
    cin >> n >> k;
    board.assign(n + 1, vector<int>(n + 1, 0));//1,1부터 시작하므로 n+1로 할당

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1; // 사과가 있으면 1
    }

    //뱀의 방향 정보 입력
    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        cmd.push_back({x, c});
    }

    cout << simulate(n, l);
    
    return 0;
}
