//���¶��ϣ���̬�滮��һ��ʵ�֣�n����С��p��Ԫ��������
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//pΪ�۸��nΪ��������
int BOTTOM_UP_CUT_ROD(int *p, int n){
	vector<int> r;//�����洢�����ȸ��������ż�ֵ
	r.push_back(0);
	for (int i = 1; i <= n; i++){
		int q = INT_MIN;
		for (int j = 1; j <= i; j++){
			q = max(q, p[j] + r[i - j]);
		}
		r.push_back(q);
	}
	return r[n];
}

int main(){
	//��ͬ���ȸ����۸�
	int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int n;
	cout << "������������ȣ� ";
	cin >> n;
	cout << "�и������ֵΪ��" << BOTTOM_UP_CUT_ROD(p, n) << endl;
	system("pause");
	return 0;
}
