#include <iostream>
#include <vector>

using namespace std;
/*2*n개의 타일을 만드는 경우의 수는 
1. (n-1)*2 의 타일을 만드는 경우의 수에 1*2타일 추가 =n-1일 때 경우의 수와 동일
2. (n-2)*2의 타일을 만드는 경우의 수에 2*1타일 2개 추가 = n-2d일때 경우의 수와 동일
따라서 n일 때 경우의 수는 1+2 = n-1일 때 경우의 수 + n-2일 때 경우의 수*/

int cntTile(int &n){
    int cnt;
    vector<int>dp(n+1, 0);
    
    dp[1] = 1; dp[2]=2;
    
    for(int i=3; i<n+1; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    
    return dp[n];
}


int main()
{
    int n;
    cin >> n;
    
    cout << cntTile(n);

    return 0;
}