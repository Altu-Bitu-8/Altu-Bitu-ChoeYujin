#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int w0, i0, t;//����ü��, ���ʴ�緮, ��ġ
	int d, i, a;//�Ⱓ, ���Ͽ��������뷮, ����Ȱ����緮
	
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a; //�Է�

	int m = i0;//��ȭx ���ʴ�緮
	int m2 = i0;//��ȭo ���ʴ�緮

	int w1 = w0; //���ʴ�緮 ��ȭ ���x ü��
	int w2 = w0; //���ʴ�緮 ��ȭ ��� o ü��
	

	for (int j = 0; j < d; j++) {
		w1 += i - (m + a);
		w2 += i - (m2 + a);

		if (abs(i - (m2 + a)) > t)
			m2 += floor((i - (m2 + a)) / 2.0); 
		//���밪�� t���� ũ�ٸ� ���ʴ�緮 m2 ��ȭ
	}
	//ù��°��-��ȭx ���
	if (w1 <= 0)//ü���� 0���ϸ� ���
		cout << "Danger Diet\n";
	else
		cout << w1 <<" "<< m << '\n'; 

	//�ι�°��-��ȭo ���
	if (w2 <= 0 || m2 <= 0)//ü����0���� or ���ʴ�緮 0���� ���
		cout << "Danger Diet";
	else {
		cout << w2 << " " << m2 << " ";
		if (m > m2)//��ȭ�� ���ʴ�緮�� ���� ���ʴ�緮���� �۴ٸ� ���
			cout << "YOYO";
		else
			cout << "NO";
	}
}
