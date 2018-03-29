//自下而上，动态规划的一种实现（n必须小于p的元素数量）
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//p为价格表，n为钢条长度
void BOTTOM_UP_CUT_ROD(int *p, int n,vector<int> &r,vector<int> &s){
	//vector<int> r;//用来存储各长度钢条的最优价值
	//vector<int> s;//用来存储各长度钢条的最优第一段长度
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
	//不同长度钢条价格
	int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int n;
	vector<int> r;
	vector<int> s;
	cout << "请输入钢条长度： ";
	cin >> n;
	BOTTOM_UP_CUT_ROD(p, n, r, s);
	cout << "切割后最大价值为：" << r[n] << endl;
	cout << "切割方案为：";
	PRINT_CUT_ROD_SOLUTION(p, n, s);
	system("pause");
	return 0;
}
