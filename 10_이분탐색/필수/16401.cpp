#include<iostream>
#include<vector>

using namespace std;

int binarySearch(long long left, long long right, int m, vector<int> &snack){
    
    while(left <=right){
        long long mid = (left + right) /2;
        int cnt =0;
        
        for(int i=0; i< snack.size(); i++){
            if(snack[i] >= mid){
                cnt += (snack[i] / mid);
            }
        }
        
        if(cnt >= m){
            left = mid + 1; 
        }
        else{
            right = mid -1;
        }
    }
    
    return left -1;
}


void snackShare(int m, vector<int>&snack){
    long long total =0;
    for(int i=0; i<snack.size(); i++){
        total += snack[i];
    }
    
    long long right = total/ m;
    long long left = 1;
    
    if(total < m){
        cout << 0;
    }
    else{
        cout << binarySearch(left, right, m, snack);
    }
}

int main(){
    
    int m, n;
    cin >> m >> n;
    vector<int> snack(n);
    
    for(int i=0; i<n; i++){
        cin >> snack[i];
    }
    
    snackShare(m, snack);
    
    return 0;
}