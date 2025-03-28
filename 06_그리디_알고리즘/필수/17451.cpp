#include <iostream>
#include <vector>
using namespace std;

/* 필요한 속력이 최고가 되기 위해서는 마지막 행성에서 비행선속도=vi여야함
따라서 입력받는 속도를 reverse 한 뒤 역산해서 지구에서의 최고 속도를 구해야함
+) vi는 int 값 범위지만 speed는 vi의 배수이므로 int 범위 초과->long 사용
*/

long findSpeed(vector<long> &planet){
    long speed = planet[0]; //구한 speed를 저장할 변수
    
    for(int i=0; i<planet.size(); i++){
        //speed는 vi 중 가장 큰 수보다 커야하므로 순회하며 값을 갱신
        if(speed < planet[i]){
            speed = planet[i];
        }
        //vi가 speed보다 작지만 배수가 아닌 경우:
        //배수가 되도록 만들어주는 최소값을 더함
        else if (speed > planet[i] && speed % planet[i] != 0){
            speed += planet[i] - (speed % planet[i]); 
        }
    }
    return speed;
}

int main()
{
    int n;
    cin>> n;
    
    vector<long>planet(n, 0);
    
    //reverse로 받기 위해 n-1부터 입력받음
    for(int i=n-1; i>=0; i--){
        cin>>planet[i];
    }
    
    cout << findSpeed(planet);

    return 0;
}