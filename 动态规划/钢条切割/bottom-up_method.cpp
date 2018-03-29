//自下而上，动态规划的一种实现（n必须小于p的元素数量）
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//p为价格表，n为钢条长度
int BOTTOM_UP_CUT_ROD(int *p, int n){
	vector<int> r;//用来存储各长度钢条的最优价值
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
	//不同长度钢条价格
	int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int n;
	cout << "请输入钢条长度： ";
	cin >> n;
	cout << "切割后最大价值为：" << BOTTOM_UP_CUT_ROD(p, n) << endl;
	system("pause");
	return 0;
}
