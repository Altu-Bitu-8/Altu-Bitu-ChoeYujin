#include <iostream>
#include <vector>
using namespace std;

//햄버거를 먹을 수 있는 최대 수를 세는 함수
int cntHam(int &k, int &n, vector<pair<char, int>>&ham){
    int cnt=0;// 사람수를 저장하는 변수
    
    for(int i=0; i < n; i++){
        if(ham[i].first == 'H'){//햄버거일 경우 continue
            continue;
        }
        if(ham[i].first == 'P'){//사람일 경우 거리가 -k인것부터 +k까지 탐색
            for(int j= i-k; j<=i+k; j++){
                if(j<0 || j>=n){//탐색 범위가 vector범위가 벗어나는지 체크
                    continue;
                }
                else{//탐색한 곳이 햄버거이고 아직 아무도 먹지 않았다면
                   if(ham[j].first == 'H' && ham[j].second == 0){
                       ham[j].second=1; //먹은 것으로 처리리
                       cnt++;
                       break;// 햄버거를 두번 이상 먹는 것을 방지하기 위해 break로 탈출
                   } 
                }
            }
        }
    }
    return cnt;
}


int main()
{
    int  n, k;
    cin >> n >> k;
    
    vector<pair<char, int>>ham; //char로 햄버거 or 사람을, int로 먹었는지 여부를 체크
    ham.assign(n, {' ', 0});//할당
    
    for(int i=0; i< n; i++){//first에 H 또는 P를 저장
        cin >> ham[i].first;
    }
    
    cout << cntHam(k, n, ham);
    
    return 0;
    
}