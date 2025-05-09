#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binarySearch(int left, int right, int target, vector<int>&card) {
	while (left <= right) {
		int mid = (right + left) / 2;

		if (target == card[mid]) {//카드를 찾은 케이스스
			return 1;
		}
		else if (target < card[mid]) {//찾고자 하는 값이 mid보다 왼쪽에 있음
			right = mid - 1;
		}
		else {// 찾고자 하는 값이 mid보다 오른쪽
			left = mid + 1;
		}
	}
	return 0; //카드를 찾지 못한 케이스
}

void find (vector<int>&card, vector<int>& nums) {
	//찾야할 숫자들을 순회->이분탐색으로 탐색->결과를 받아와서 출력
	for (int i = 0; i < nums.size(); i++) {
		//left와 right는 카드의 인덱스 번호
		cout << binarySearch(0, card.size() - 1, nums[i], card)<<" ";
	}
}

int main() {
	int n, m;
	//상근이가 갖고 있는 카드 input
	cin >> n;
	vector<int>card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());//카드 입력 후 정렬

	//찾아야할 카드 input
	cin >> m;
	vector<int> nums(m);
	for (int i = 0; i < m; i++) {
		cin >> nums[i];
	}

	find(card, nums);
	return 0;
}