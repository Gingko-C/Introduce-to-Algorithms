#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int v_num, w_num;
	cin >> v_num >> w_num;
	vector<vector<int>> v(v_num,vector<int>(v_num,INT_MAX));
	int bv, ev, wl;
	int baseP = 0, temp;
	vector<bool> flag(v_num, false);
	vector<int> v_S(v_num, INT_MAX);
	vector<vector<int>> v_S_w(v_num);
	for (int i = 0;i < w_num;i++) {
		cin >> bv >> ev >> wl;
		v[bv][ev] = wl;
		//v[ev][bv] = wl;  //无向图
		if (bv == 0) {
			v_S[ev] = wl;
			v_S_w[ev] = { 0,ev };
		}
		//if (ev == 0) v_S[bv] = wl;  //无向图

	}
	for (int i = 0;i < v_num;i++) {
		v[i][i] = 0;
	}
	v_S[0] = 0;
	v_S_w[0] = { 0 };
	flag[0] == true;
	int min;
	for (int j = 1;j < v_num;j++) {
		min = INT_MAX;
		for (int i = 0;i < v_num;i++) {
			if (flag[i] == false && v_S[i] < min) {
				min = v_S[i];
				baseP = i;
			}
		}
		flag[baseP] = true;

		for (int i = 0;i < v_num;i++) {
			temp = (v[baseP][i] == INT_MAX) ? INT_MAX : v_S[baseP] + v[baseP][i];
			if (flag[i] == false) {
				vector<int> temp_w = v_S_w[baseP];
				temp_w.push_back(i);
				if (temp < v_S[i]) {
					v_S[i] = temp;
					v_S_w[i] = temp_w;
				}
			}
		}
	}
	for (int i = 0;i < v_num;i++) {
		int flag_cout = false;
		if (v_S[i] == INT_MAX) cout << "X" << endl;
		else {
			for (auto w : v_S_w[i]) {
				if (flag_cout == false) {
					cout << w;
					flag_cout = true;
				}
				else {
					cout << "->" << w;
				}
			}
			cout << " " << v_S[i] << endl;
		}
	}
	system("pause");
	return 0;
}


//输入：
//6 8
//0 2 10
//0 4 30
//0 5 100
//1 2 5
//2 3 50
//3 5 10
//4 5 60
//4 3 20
//输出：
//0 X 10 50 30 60