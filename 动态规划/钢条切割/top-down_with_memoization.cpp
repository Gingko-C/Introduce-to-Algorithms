//加入备忘的自上而下，动态规划的一种实现，时间复杂度o(n^2)远好于o(2^n)的朴素递归 （n必须小于p的元素数量）
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//p为价格表，n为钢条长度，r用来记录已经计算的n-i长度钢条的最优价值避免重复计算（！！需引用）
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
	//不同长度钢条价格
	int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int n;
	cout << "请输入钢条长度： ";
	cin >> n;
	vector<int> r;//用来存储各长度钢条的最优价值
	for (int i = 0; i <= n; i++){
		r.push_back(INT_MIN);
	}
	cout << "切割后最大价值为：" << MEMOIZED_CUT_ROD(p, n, r) << endl;
	system("pause");
	return 0;
}
