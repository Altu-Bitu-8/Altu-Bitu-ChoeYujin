#include <iostream>
#include <queue>

using namespace std;

int suffle(queue<int> &card, int &n){
    for(int i = 1; i<=n; i++){ //1부터 N까지 push
        card.push(i);
    }
    
    while(card.size() != 1){
        card.pop(); //맨 윗장 카드 빼기
        int temp = card.front();//맨 위의 카드를 뒤로 보내기
        card.pop();
        card.push(temp);
    }
    
    return card.front();
}

int main(){
    
    int n;
    cin >> n;
    queue<int>card;//큐로 카드덱을 구현현
    
    cout << suffle(card, n);
    
    return 0;
}