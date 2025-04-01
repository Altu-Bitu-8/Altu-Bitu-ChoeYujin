#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
프로그램 전체 구조:
1. input을 arr 백터에 저장
2. arr 원소 최대값까지의 소수를 구함->is_prime에 저장:getPrimes()
3. input=a+b를 만족하는 소수 중 작은값 a를 리턴: goldbach()
*/


// 소수 여부 반환 함수: 에라토스테네스의 체 이용
vector<bool> getPrimes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;//0과1을 소수가 아니므로 false
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) {//이미 소수가 아닌것으로 기록되어 있다면 continue
            continue;
        }
        for (int j = i * i; j <= n; j += i) {//
            is_prime[j] = false;
        }
    }
    return is_prime;
}

// n = a + b를 만족시키는 a 반환
int goldbach(int n, vector<bool> &is_prime) {
    for (int a = 3; a <= n / 2; a+= 2) {
        // 2보다 큰 짝수 소수는 존재하지 않으므로
        // a = 3부터 탐색해도 a와 b 모두 홀수여야 한다는 조건 만족
        if (is_prime[a] && is_prime[n - a]) {//a도 소수고 n-a도 소수라면 리턴
            return a;
        }
    }
    // n = a + b를 만족시키는 홀수 소수 a, b가 없으면 0 반환
    return 0;
}

/* [백준 6588: 골드바흐의 추측]
 * 1. 3보다 크거나 같고 n / 2보다 작거나 같은 소수 a를 오름차순으로 탐색한다.
 * 2. 1에서 찾은 a에 대하여 n - a(=b)도 소수이면 골드바흐의 추측이 성립한다.
 * 3. 골드바흐의 추측이 성립하면 a를, 성립하지 않으면 0을 반환한다.
 */

int main() {
    // 입력
    vector<int> arr;//입력으로 들어온 원소를 저장할 벡터
    int input;
    while(1) {
        cin >> input;
        if (input == 0) {//0이 입력되면 프로그램 종료
            break;
        }
        arr.push_back(input);//input으로 들어온 값을 arr의 원소로 추가
    }

    // 연산
    //100만까지의 소수 판별->비효율적, 따라서 들어온 input 값 중 최대값까지의 소수여부만으 구함
    int max_num = *max_element(arr.begin(), arr.end()); // 벡터의 최댓값
    vector<bool> is_prime = getPrimes(max_num);//원소 최대값 이하의 소수들의 집합

    for (int i = 0; i < arr.size(); i++) {//vector안 원소들을 대상으로 골든바흐 추측
        int a = goldbach(arr[i], is_prime);

        // 출력
        if (a != 0) { // n = a + b를 만족하는 a, b가 존재하면
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n";
        } else {      // 존재하지 않으면
            cout << "Goldbach's conjecture is wrong.\n";//정해진 문구 출력
        }
    }
    return 0;
}