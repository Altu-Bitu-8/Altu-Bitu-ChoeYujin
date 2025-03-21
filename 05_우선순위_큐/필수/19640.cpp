#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//struct를 이용해 한 사람의 정보를 묶어서 저장함
struct info {
    int idx;        // 처음 줄에 선 번호
    int line_num;   // m개의 줄 중 속한 줄의 번호
    int work_days;  // 근무 일수
    int urgency;    // 급한 정도
};

//우선순위큐에서 순서를 어떻게 처리할지 struct로 직접 정의
struct cmp {
    bool operator()(const info &child, const info &parent) {
        if (parent.work_days != child.work_days) {
            return parent.work_days > child.work_days;//일수가 큰 쪽 우선
        }
        if (parent.urgency != child.urgency) {
            return parent.urgency > child.urgency;//급한정도가 큰 쪽 우선
        }
        return parent.line_num < child.line_num;//줄 번호가 작은 사람 우선
    }
};

//몇번째 화장실을 쓰는지 계산하는 함수
int simulation(int m, int k, vector<queue<info>> &lines) {
    // 각 줄의 선두들이 저장되는 우선순위 큐
    //앞서 정의한 info와 cmp를 사용
    priority_queue<info, vector<info>, cmp> pq;

    // 우선순위 큐 초기화
    for (int i = 0; i < m; i++) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }

    // k 차례가 오기 전 화장실을 사용한 사람의 수
    int count = 0;

    while (!pq.empty() && pq.top().idx != k) {  // k의 차례가 되기 전까지
        int line_num = pq.top().line_num;
        pq.pop();

        //줄에서 t선두에 있는 다음 사람을 꺼내 우선순위큐에 넣기
        if (!lines[line_num].empty()) {
            pq.push(lines[line_num].front());
            lines[line_num].pop();
        }

        count++;//사용한 사람 수 증가
    }
    //pq.top().idx == k가 되어 while문 탈출->count를 반환
    return count;
}

/**
 * [화장실의 규칙] - 우선순위 큐 & 시뮬레이션 문제
 *
 * 1. 각 사람은 (온 순서 % m) 번째 줄의 뒤에 서게 된다.
 * 2. 매 순간, 모든 줄의 앞 사람 중에 우선 순위가 가장 높은 사람부터 화장실을 이용한다.
 *
 * <우선순위>
 * 1. 근무 일자가 많은 사람
 * 2. 더 급한 사람
 * 3. 줄 번호가 앞선 사람
 *
 * ---
 * 1. 각 줄은 먼저 온 사람이 먼저 나가기 때문에, 큐를 이용해 저장한다.
 * 2. 모든 줄의 선두를 우선순위 큐에 넣고, 우선순위가 가장 앞선 사람부터 삭제한다.
 * 3. 어떤 줄의 선두가 화장실을 이용했으면, 그 줄의 선두를 우선 순위 큐에 넣는다.
 *
 * 이때, 0번부터 표기하므로 데카의 idx는 k가 된다.
 *
 * !주의! 큐에서 사람을 빼서 우선 순위 큐에 넣을 때, 항상 큐가 비어있지 않은지 확인
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, d, h;
    cin >> n >> m >> k;

    vector<queue<info>> lines(m, queue<info>());

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> d >> h;
        lines[i % m].push({i, i % m, d, h});//n명의 사람을 i%d번째 줄에 배치
    }

    // 연산 & 출력
    cout << simulation(m, k, lines);

    return 0;
}