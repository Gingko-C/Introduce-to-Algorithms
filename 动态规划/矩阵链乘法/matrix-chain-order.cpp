//算法导论（原书第三版）15.2 算法的C++实现
#include<iostream>
#include<vector>
using namespace std;
#define MAT_NUM 6

void MATRIX_CHAIN_ORDER(int *p, int m[MAT_NUM + 1][MAT_NUM + 1], int s[MAT_NUM + 1][MAT_NUM + 1]){
	for (int i = 1; i <= MAT_NUM; i++) m[i][i] = 0;
	for (int l = 2; l <= MAT_NUM; l++){
		for (int i = 1; i <= MAT_NUM - l + 1; i++){
			int j = i + l - 1;
			int q = INT_MAX;
			for (int k = i; k < j; k++){
				m[i][j] = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q>m[i][j]){
					q = m[i][j];
					s[i][j] = k;
				}
			}
			m[i][j] = q;
		}
	}
	
	for (int i = 1; i <= MAT_NUM; i++){
		for (int l = 2; l <= MAT_NUM; l++){
			
			
		}
	}
}
//打印函数还没理解
void PRINT_OPTIMAL_PARENS(int s[MAT_NUM+1][MAT_NUM+1], int i, int j){
	if (i == j) cout << "A" << i;
	else {
		cout << "(";
		PRINT_OPTIMAL_PARENS(s, i, s[i][j]);
		PRINT_OPTIMAL_PARENS(s, s[i][j] + 1, j);
		cout << ")";
	}
}

int main(){
	int p[MAT_NUM+1] = { 30, 35, 15, 5, 10, 20, 25 };//MAT_NUM个相容矩阵的行列值
	int m[MAT_NUM + 1][MAT_NUM + 1];//存储m[i,j]：Ai~Aj的最小代价括号化方案
	int s[MAT_NUM + 1][MAT_NUM + 1];//存储s[i,j]最小代价括号化方案的划分位置k
	MATRIX_CHAIN_ORDER(p, m, s);
	PRINT_OPTIMAL_PARENS(s, 1, 6);
	cout << endl;
	system("pause");
	return 0;
}