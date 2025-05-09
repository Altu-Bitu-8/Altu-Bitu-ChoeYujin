#include <iostream>
#include <vector>

using namespace std;
/*이분탐색으로는 어떻게 접근해야할질 잘 모르겠어서 일단은 일반 구현으로 풀었습니다
이분탐색으로는 문제를 어떻게 접근하면 좋을지 알려주시면 감사하겠습니다.*/


int findHeight(int n, int m, vector<int>&light){
  int height = 0;
  
  //for문으로 순회 -> 가로등 사이의 거리/2의 최대값을 찾음
  for(int i=1; i<m; i++){
      int h = (light[i] - light[i-1] + 1) /2;
      height = max(h, height); //거리/2 최대값 갱신
  }
  
  //가로등끼리의 거리를 체크했으므로 시작점과 종착점도 불빛이 닿는지 체크
  height = max(height, light[0]); // 시작점 -0번째 가로등까지의 거리보다 커야함
  height = max(height, (n - light[m-1]));//종착점-m-1번째 가로등까지의 거리보다 커야함
  
  return height;
}

int main()
{   
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    
    //input
    int n, m;
    cin >> n>> m;
    vector<int>light(m);
    
    for(int i=0; i<m; i++){
        cin >> light[i];
    }
    
    cout << findHeight(n, m, light);
    return 0;
}