
#include <iostream>
#include <vector>
#include <deque>//앞뒤로 삭제/삽입이 가능 deque를 이용

using namespace std;

//deque를 포함한 2차원 vector를 이용해 card라는 이름의 자료구조 선언
//자료구조 card에 deck이라는 이름의 vector가 있고 그 안에 도도와 수연의 카드가 deque로 구현되어있음
typedef vector<deque<int>> cards;  // 0: 도도, 1: 수연
const int DO = 0, SU = 1;

/** 승리 판단하기 */
string judge(cards& deck) {//덱을 인자로 받아 승부결과(do/su/dosu)를 반환
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();//do_deck, su_deck으로 둘의 덱의 카드수를 받음음
	if (do_deck > su_deck) {//do의 덱에 카드가 더 많이 남았을 경우
		return "do";//도도의 승리리
	}
	else if (do_deck < su_deck) {//수연의 덱에 카드가 더 많이 남았을 경우
		return "su";//수연의 승리
	}
	return "dosu";//위의 두 케이스에 해당x = 카드의 수가 같음 = 무승부부
}

/** 그라운드에서 덱으로 카드 옮기기 */
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) {//그라운드에 카드가 있는 동안
		deck.push_back(ground.back());//그라운드에 있는 카드를 덱의 맨 뒤에 push
		ground.pop_back();//그라운드에서 해당 카드 삭제제
	}
}

/** 종을 쳤을 때 */
void ringTheBell(int player, cards& deck, cards& ground) {//종을 침->규칙에 따라 그라운드에 있는 카드를 가져감감
	groundToDeck(deck[player], ground[!player]);// 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


/** 종을 울릴 수 있는 사람 판단 */
int whoCanRingTheBell(cards& deck, cards& ground) {//그라운드와 덱에 남은 카드로 종 울릴 수 있는 사람을 판단단
	if (!ground[DO].empty() && ground[DO].front() == 5) { //도도덱에서 5가 나왔을 때
		return DO;//도도가 종을침침
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { //수연이 덱에서 5가 나왔을 때
		return DO;//도도가 종을 침침
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 수연
		return SU;//카드가 비여있지 않음&&두 카드의 합이 5가 됨->수연이가 종을 침침
	}
	return -1; // 종을 울릴 수 없음
}

/** 게임 진행 */
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도 먼저(DO=0으로 정의한 것을 사용용)
	while (m--) {//m번만큼 반복복
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front();//덱에서 내려놓은 카드 삭제(pop)
		if (deck[turn].empty()) {//덱이 비어있다면면
			break;//m번만큼 반복하지 않고 탈출->승패를 판단단
		}

		int bell = whoCanRingTheBell(deck, ground); // 카드를 내려 놓을 때마다 종을 울릴 수 있는지 판단단
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground);//ringTheBell함수를 통해 그라운드에 있는 카드를 가져갈 수 있게함함
		}
		turn = !turn; // 차례 바꾸기(bool값이므로 !로 전환이 가능) do->su/ su->do
	}
	return judge(deck);//m번만큼 반복했다면 남은 덱을 이용해 누가 이겼는지 판단(judge함수수)
}

/**
 * 도도, 수연이 각각 덱과 그라운드를 가짐
 * 도도->수연->도도->수연... 순으로 차례를 바꿔가며 게임 진행 (game 함수)
 * 1. 카드를 덱에서 한 장 내려놓음
 * 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
 * 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell, groundToDeck 함수)
 * 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
 */

int main() {
	int n, m, card1, card2;//필요한 변수 선언언
    //위에서 선언한 card 자료 구조를 이용해 deck과 ground 정보를 저장할 자료구조 선언언
	cards deck(2), ground(2); // 0: 도도, 1: 수연

	// 입력
	cin >> n >> m;
	while (n--) {//n개의 카드를 입력 받기기
		cin >> card1 >> card2;
		deck[DO].push_front(card1);//do의 카드덱에 카드 추가. 밑의 카드부터 입력받으므로 front로 push
		deck[SU].push_front(card2);//su의 카드덱에 카드 추가가
	}

	// 출력 & 연산
	cout << game(m, deck, ground);//승부 결과 연산과 동시에 출력력

	return 0;
}