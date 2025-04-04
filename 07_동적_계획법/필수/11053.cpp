#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 생각해봐야하는 케이스
1. arr[i]< arr[i-1]: 증가 안 함
1-1. arr[0]~arr[i] 중에 arr[i]가 가장 작음 
    -> 후에 더 큰 원소가 증가하면서 arr[i]가 부분수열의 시작 원소가 될 수 있음(1-2케이스)
1-2. arr[0]~arr[i-1] 중에 arr[i] 보다 작은 원소가 있음(=arr[j])
    ->arr[j]를 포함한 부분수열의 다음 원소로 arr[i]가 올 수 있음
    ->dp[i]=max(dp[i-1], dp[j]+1);
    */

int longArr(int &n, vector<int>&arr){
    vector<int>dp(n, 1); //dp[i] = arr[i] 수열까지의 가장 긴 부분 수열의 길이
    int max_length=1;
    
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){//이전의 원소 중에 arr[i]보다 작은 원소가 있는지 탐색
            if(arr[j] < arr[i]){//작은 원소가 있다면 arr[j]로부터 증가수열을 이어나갈수 있음
                //j를 순회하며 부분수열 중 길이가 긴 것을 저장
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        //dp 원소 중 가장 큰 값을 저장장
        max_length = max(dp[i], max_length);
        
    }
    return max_length;
}


int main()
{
    //입력
    int n;
    cin >> n;
    
   vector<int>arr(n);
   for(int i=0; i<n; i++){
       cin >> arr[i];
   }
    
    //출력
    cout << longArr(n, arr);
    return 0;
}