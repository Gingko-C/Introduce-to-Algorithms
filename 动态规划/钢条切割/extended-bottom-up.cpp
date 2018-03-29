//���¶��ϣ���̬�滮��һ��ʵ�֣�n����С��p��Ԫ��������
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//pΪ�۸��nΪ��������
void BOTTOM_UP_CUT_ROD(int *p, int n,vector<int> &r,vector<int> &s){
	//vector<int> r;//�����洢�����ȸ��������ż�ֵ
	//vector<int> s;//�����洢�����ȸ��������ŵ�һ�γ���
	r.push_back(0);
	s.push_back(0);
	for (int i = 1; i <= n; i++){
		int q = INT_MIN;
		s.push_back(INT_MIN);
		for (int j = 1; j <= i; j++){
			if (q < p[j] + r[i - j]){
				q = p[j] + r[i - j];
				s[i] = j;
			}
		}
		r.push_back(q);
	}
	//return r[n];
}
void PRINT_CUT_ROD_SOLUTION(int *p, int n, vector<int> &s){
	while (n>0){
		cout << s[n] << " ";
		n -= s[n];
	}
	cout << endl;
}
int main(){
	//��ͬ���ȸ����۸�
	int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int n;
	vector<int> r;
	vector<int> s;
	cout << "������������ȣ� ";
	cin >> n;
	BOTTOM_UP_CUT_ROD(p, n, r, s);
	cout << "�и������ֵΪ��" << r[n] << endl;
	cout << "�и��Ϊ��";
	PRINT_CUT_ROD_SOLUTION(p, n, s);
	system("pause");
	return 0;
}
