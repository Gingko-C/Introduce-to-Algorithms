//朴素的自上而下递归，在n稍大的情况下就会需要巨大的计算时间，时间复杂度为o(2^n) （n必须小于p的元素数量）
#include<iostream>
#include<algorithm>
using namespace std;

//p为价格表，n为钢条长度
int CUT_ROD(int *p, int n){
	if (n == 0) return 0;
	int q = INT_MIN;
	for (int i = 1; i <= n; i++)
		q = max(q, p[i] + CUT_ROD(p, n - i));
	return q;
}

int main(){
	//不同长度钢条价格
	int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int n;
	cout << "请输入钢条长度： ";
	cin >> n;
	cout << "切割后最大价值为：" << CUT_ROD(p, n) << endl;
	system("pause");
	return 0;
}
