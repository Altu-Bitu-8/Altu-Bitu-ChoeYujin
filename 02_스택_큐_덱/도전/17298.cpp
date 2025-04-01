#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*처음에는 stack에 원소 값을 직접 저장하는 방식으로 풀음->시간초과...
따라서 stack 원소의 값이 아닌 원소의 인덱스를 저장
    ->for문으로 해당 원소가 저장된 2차원 배열을 탐색하지 않아도x ->시간 단축축
*/

//오큰수를 탐색하는 함수수
void cmp(int &a, vector<vector<int>> &ans, stack<int> &st, int &i){
    while(!st.empty() && ans[st.top()][0] < a){//a가 스택의 top보다 큼->오큰수를 찾음
        ans[st.top()][1]=a; //오큰수를 저장
        st.pop(); //오큰수를 찾았으니 stack에서 pop
        
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    stack<int>st;
    //2차원 벡터 배열에 원소값과 오큰수를 저장
    vector<vector<int>> ans(n, vector<int>(2));
    
    for (int i=0; i<n; i++){
        
        int a;
        cin>> a;
        
        ans[i][0]=a;
        ans[i][1]=-1; //오큰수를 찾기전까진 답을 -1초기화
        
        cmp(a, ans, st, i);
        
        st.push(i); //스택에 인덱스를를
    }
    
    //오큰수 출력력
    for(int i=0; i<n; i++){
        cout<<ans[i][1]<<" ";     
    } 
    return 0;
}