#include <iostream>
#include <vector>

using namespace std;
vector<int>child[50]; //부모노드는 입력으로 들어오지만 자식노드는 알려주지x 따로 저장해야함
bool del[50];//삭제된 노드는 true로 처리
int cnt=0;

void deleteNode(int num){//인자로 받은 노드의 자식노드까지 삭제하는 함수
    del[num] = true;//삭제 처리
    for(int i=0; i<child[num].size(); i++){//num노드의 자식 노드를 순회
        deleteNode(child[num][i]);//재귀로 삭제처리
    }
}

void cntLeaf(int n){
    for(int i=0; i<n; i++){
        if(del[i] == false){//삭제되지 않았다면
            bool check=true;//일단 리프 노드가 맞다고 가정
            for(int j=0; j<child[i].size(); j++){//자식노드를 순회하면서
                if(del[child[i][j]] == false){//살아 있는 자식노드가 있다면
                    check = false; //거짓으로 체크
                }
            }
            if(check == true){
                cnt++; //자식들을 순회하고도 check가 true->모든 자식 노드가 삭제됐다는 뜻->리프노드
            }
        }
        
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a; 
        cin >> a;
        //루트노드일 케이스: 인덱스 번호를 벗어나므로 예외처리
        if(a == -1){
            continue;  
        }
        else{
            child[a].push_back(i); //a노드의 자식은 i노드
        }
    }
    
    //노드 삭제
    int num;
    cin >> num;
    deleteNode(num);
    
    //리프노드 세기
    cntLeaf(n);
    cout << cnt;
    
    
    return 0;   
}