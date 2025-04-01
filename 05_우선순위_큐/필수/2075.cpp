#include<iostream>
#include<queue>

using namespace std;

/*n번째 큰 수를 모든 수를 다 안 저장하고 찾는 방법
-> 큐의 크기가 n을 넘어가는 순간 가장 작은 숫자를 pop
-> 모든 숫자를 입력받고 난 뒤 가장 큰 수 n개만 오름차순으로 남음
-> 이 때 top()에 있는 수가 n번째로 큰 숫자(남은 숫자 중에 가장 작으므로)
*/
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> square;
	int n;
	cin >> n;

	for (int i = 0; i < n * n; i++) {
		int num;
		cin >> num;
		square.push(num);

		if (square.size() > n) {// n개 저장하면 마지막에 top에는 원하는 n번째 수가 오게 됨
			square.pop(); //저장되어 있는 숫자 중 가장 작은 수를 pop
		}
	}
	cout << square.top(); //n번째로 큰 숫자가 top에 위치
}