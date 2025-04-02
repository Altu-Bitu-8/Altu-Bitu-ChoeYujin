#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//알파벳 빈도수를 벡터로 반환하는 함수
vector<int>countLetter(string word){
    vector<int>letter(26,0); 
    for(char ch : word){
        letter[ch -'A']++; //해당 글자수 카운트++
    }
    
    return letter;
}



int main(){
    int n;
    int cnt=0; //비슷한 단어수를 세는 정수
    string word;
    
    cin >> n;
    cin >> word;//비교할 첫번째 단어 입력받기
    
    vector<int>standard=countLetter(word); //기준이 될 첫번째 단어어
   
    
    for(int i=0; i<n-1; i++){
        string temp;
        cin >> temp;
        
        vector<int>cmp=countLetter(temp);
        int a=0;
        
        for(int j= 0; j<26; j++){
            a = abs(cmp[j] - standard[j]);
        }
        
        //단어가 같거나(0) or 하나만 다른 경우(1)
        if(a==0 || a==1){
            cnt++;
        }
        //하나만 교체하면 되는 경우: 길이가 같고 다른게 2개개
        else if(a ==2 && temp.length() == word.length()){
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}