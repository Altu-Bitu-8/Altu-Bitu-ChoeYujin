#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){
	string s;
	cin >> s;

	//�߸� ���ڿ��� ������ �ڷᱸ��, set:�ߺ�x�� ����
	//�ش� ������ ������ �ʿ������ �����Ƿ� unordered_set�� ����� ��� �ð����⵵ ����
	set<string> block; 

	for(int i=0; i<s.size(); i++){//���깮�ڿ� ���� �ε���
	    for(int j=1; j<=s.size(); j++){//���� ���ڿ� ������
	        block.insert(s.substr(i, j));
	    }
	}

	cout << block.size(); //set�� ���� �� ��ȯ

}	