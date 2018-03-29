//���뱸�������϶��£���̬�滮��һ��ʵ�֣�ʱ�临�Ӷ�o(n^2)Զ����o(2^n)�����صݹ� ��n����С��p��Ԫ��������
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//pΪ�۸��nΪ�������ȣ�r������¼�Ѿ������n-i���ȸ��������ż�ֵ�����ظ����㣨���������ã�
int MEMOIZED_CUT_ROD(int *p, int n, vector<int> &r){
	if (r[n] >= 0)return r[n];
	int q = INT_MIN;
	if (n == 0)q = 0;
	else{
		for (int i = 1; i <= n; i++){
			q = max(q, p[i] + MEMOIZED_CUT_ROD(p, n - i, r));
		}
	}
	r[n] = q;
	return q;
}

int main(){
	//��ͬ���ȸ����۸�
	int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int n;
	cout << "������������ȣ� ";
	cin >> n;
	vector<int> r;//�����洢�����ȸ��������ż�ֵ
	for (int i = 0; i <= n; i++){
		r.push_back(INT_MIN);
	}
	cout << "�и������ֵΪ��" << MEMOIZED_CUT_ROD(p, n, r) << endl;
	system("pause");
	return 0;
}
