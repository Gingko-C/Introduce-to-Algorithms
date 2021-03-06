#include <vector>
using std::vector;
#include <map>
using std::map;
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <algorithm>
#include <queue>
#include <iomanip>
#include <time.h>
using std::queue;

#define INT_MAX 100000

struct BFS_Node
{
	int color = 0;
	int d = INT_MAX;
	int index;
};

int main() {
	int vnum, pi;
	double sp, r;
	int max_level = 0;
	cin >> vnum >> sp >> r;
	double destp = sp;
	vector<BFS_Node> nodes(vnum);
	vector<vector<int>> childnodes(vnum);
	int max_level_nodes = 0;
	int s;
	for (int i = 0;i < vnum;i++) {
		cin >> pi;
		nodes[i].index = i;
		if (pi == -1) s = i;
		else childnodes[pi].push_back(i);
	}
	nodes[s].color = 1;
	nodes[s].d = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int temp_node = q.front();
		q.pop();
		for (int i:childnodes[temp_node]) {
			if (nodes[i].color == 0) {
				nodes[i].color = 1;
				nodes[i].d = nodes[temp_node].d + 1;
				q.push(i);
				if (nodes[i].d > max_level) {
					max_level = nodes[i].d;
				}
			}
		}
	}

	for (int i = 0;i < max_level;i++) {
		destp *= (1 + 0.01*r);
	}
	for (int i = 0;i < vnum;i++) {
		if (nodes[i].d == max_level) {
			max_level_nodes++;
		}
	}
	cout << std::fixed << std::setprecision(2) << destp << " " << max_level_nodes << endl;
	//printf("%.2lf %d\n", destp, max_level_nodes);
	system("pause");
	return 0;
}



//输入例子:
//9 1.80 1.00
//1 5 4 4 - 1 4 5 3 6
//
//输出例子 :
//	1.85 2