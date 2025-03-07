//gcd[|A1-S|,|A2-S|,....]을 구하는 문제
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findGcd(int a, int b){//두 수의 최대공약수 찾기
    while(b!=0){
        int temp = a % b;
        a = b;
        b=temp;
    }
    return a;
}

int findD(vector<int> &distance, int &n){
    
    int d =distance[0];
    
    for(int i=1; i<n; i++){//dis배열 모든 원소의 최대공약수
        d = findGcd(d, distance[i]);//배열을 순회하며 최대공약수를 갱신
    }
    
    return d;
}


int main(){
    int n, s;
    cin >> n>> s;
    
   vector <int> distance(n);
    
    for(int i =0; i<n; i++){
        int ai;
        cin >> ai;
        distance[i] = abs(ai - s);
    }
    
    cout << findD(distance, n);
    
    return 0;
}