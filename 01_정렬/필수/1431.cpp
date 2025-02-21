#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
	int alength = a.size();
	int blength = b.size();
	int asum = 0;
	int bsum = 0;//�ʱ�ȭ

	if (a.size() != b.size()) //���� ������� ����
		return a.size() < b.size();

	for (int i = 0; i < a.size(); i++) {//���̰� ���� ���� a�� ��������
		if ('0' <= a[i] && a[i] <= '9') //�����϶�
			asum += int(a[i]) - 48;//���� ����
	}
	for (int i = 0; i < b.size(); i++) {//b�� ������
		if ('0' <= b[i] && b[i]<= '9') //�����϶�
			bsum += int(b[i]) - 48;//���� ����
	} 
	if (asum != bsum) 
		return asum < bsum;//���̰� ���ٸ� ���ڵ��� ������ ����

	return a < b; // ���� ���ٸ� ���������� ����

}

int main()
{
	int n;
	cin >> n;
	string s[50]; //�ø��� �ִ� ���̰� 50�̹Ƿ�

	for (int i = 0; i < n; i++) {
		cin >> s[i]; //�ø����� �Է¹���
	}

	sort(s, s + n, cmp); //��ܿ��� ���� ��Ģ��� ����
	
	for (int i = 0; i < n; i++)
		cout << s[i] << '\n'; //������ ���� ���
}