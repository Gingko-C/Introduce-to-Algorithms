//���ص����϶��µݹ飬��n�Դ������¾ͻ���Ҫ�޴�ļ���ʱ�䣬ʱ�临�Ӷ�Ϊo(2^n) ��n����С��p��Ԫ��������
#include<iostream>
#include<algorithm>
using namespace std;

//pΪ�۸��nΪ��������
int CUT_ROD(int *p, int n){
	if (n == 0) return 0;
	int q = INT_MIN;
	for (int i = 1; i <= n; i++)
		q = max(q, p[i] + CUT_ROD(p, n - i));
	return q;
}

int main(){
	//��ͬ���ȸ����۸�
	int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int n;
	cout << "������������ȣ� ";
	cin >> n;
	cout << "�и������ֵΪ��" << CUT_ROD(p, n) << endl;
	system("pause");
	return 0;
}
