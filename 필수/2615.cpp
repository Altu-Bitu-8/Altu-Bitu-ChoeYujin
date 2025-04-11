#include <iostream>
#include <vector>
/*가장 왼쪽 위에 있는 돌을 기준으로 탐색하므로 2,3,5,6시 방향으로 탐색색*/
using namespace std;

vector<int>board[19];//바둑판을 vector배열로 저장장

bool find2(int color, int x, int y){//x++, y--로 움직임임
    //돌 수 카운트
    for(int i=0; i<5; i++){
        if(y-i <0 || x+i >18) return false; //범위값을 벗어나면 바로 false
        if(board[y-i][x+i] != color)  return false; //5개를 세는 와중에 다른색 돌이 나오면 false
    }
    //6목 방지를 위해 0번째와 6번째 돌이 존재하는지, 존재한다면 다른 색상인지 검사사
    if((x-1<0 || y+1>18 || board[y+1][x-1] !=color) && (x+5>18 || y-5<0||board[y-5][x+5] != color)){
        return true;
    }
    return false;
}

bool find3(int color, int x, int y){//x++로 움직임
    //돌 수 5개인지 카운트
    for(int i=0; i<5; i++){
        if(x+i >18) return false; //범위값을 벗어나면 바로 false
        if(board[y][x+i] != color)  return false; //5개를 세는 와중에 다른색 돌이 나오면 false
    }
    
    //0번째, 6번재 돌이 다른색인지 확인
    if((x-1<0 || board[y][x-1] !=color) && (x+5>18 || board[y][x+5] != color)){
        return true;
    }
    
    return false;
}

bool find5(int color, int x, int y){//x++, y++로 움직임
    //돌 수 카운트
    for(int i=0; i<5; i++){
        if(y+i >18 || x+i >18) return false; //범위값을 벗어나면 바로 false
        if(board[y+i][x+i] != color)  return false; //5개를 세는 와중에 다른색 돌이 나오면 false
    }
    
    //0번째 6번째 돌
    if((x-1<0 || y-1 <0 || board[y-1][x-1] !=color) && (x+5>18 || y+5>18 || board[y+5][x+5] !=color)){
        return true;
    }
    
    return false;
}

bool find6(int color, int x, int y){// y++로 움직임
    //돌 수 카운트
    for(int i=0; i<5; i++){
        if(y+i>18) return false; //범위값을 벗어나면 바로 false
        if(board[y+i][x] != color)  return false; //5개를 세는 와중에 다른색 돌이 나오면 false
    }
    //6목 방지를 위해 0번, 6번 돌이 같은 색상인지 체크
    if((y-1<0 || board[y-1][x] !=color) && (y+5>18 || board[y+5][x] != color)){
        return true;
    }
    return false;
}

void win(){
    //검은돌부터 탐색
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            if(find2(1, j, i) || find3(1, j, i) || find5(1, j, i) || find6(1, j, i)){
                cout << 1 <<"\n";
                cout << i+1 << " "<<j+1;//인덱스는 0번부터 시작하므로 +1
                exit(0); //불필요하게 0을 출력하는 것을 막기 위해 바로 exit
            }
        }
    }
    //흰돌 탐색
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            if(find2(2,j, i) || find3(2, j, i) || find5(2, j, i) || find6(2, j, i)){
                cout << 2 <<"\n";
                cout << i+1 << " "<<j+1;
                exit(0);
            }
        }
    }
    
    //무승부시
    cout<<0;
}

int main()
{
    //input
    for(int i=0; i< 19; i++){
        for(int j=0; j<19; j++){
            int a;
            cin >> a;
            board[i].push_back(a);
        }
    }
    
    win();
}