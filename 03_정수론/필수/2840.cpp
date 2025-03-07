#include <iostream>
#include <vector>
#include <set>

using namespace std;

void makeWheel(int &n, int &now, char &ch, vector<char>&wheel, int &flag, set<char>&duplication){
    now = now%n;
    
    if(duplication.count(ch) == 1 && wheel[now] != ch ){//동일칸이 아닌데 이미 나온 글자가 들어옴->!
        flag = 1;
    }
        
    else if(wheel[now] == '?' ){//비어있음
        wheel[now] = ch;
        duplication.insert(ch);//중복확인 리스트에 추가
    }
    else if(wheel[now] != ch){//칸안에 알파벳이 중복->해당하는 바퀴가 없음
        flag = 1;
    }
}


int main()
{
    int n, k;
    int flag=0;//바퀴가 존재가능한지 표시하는 플래그
    int now=0; //현재의 화살표 위치
    cin >> n >> k;
    
    vector <char> wheel(n, '?');
    set<char> duplication;
    
    while(k--){
        int num;
        char ch;
        cin >> num>>ch;
        
        now += num;
         
        makeWheel(n, now, ch, wheel, flag, duplication);
        
    }
    
    //출력
    if(flag == 1){
        cout <<"!";
    }
    else{
        for(int i =0; i<n; i++){
            int temp = (now + n -i) %n;
            cout << wheel[temp];
        }
    }
    
    
    return 0;
}