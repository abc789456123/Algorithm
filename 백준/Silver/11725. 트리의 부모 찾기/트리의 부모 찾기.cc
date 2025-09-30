#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//직접 올라가면서 부모를 하나하나씩 찾아주는 함수
//시간초과 나서 실패
int find_parent(vector<vector<int>>& tree, int node) {
	vector<int> nodes = tree[node];
	vector<bool> save(tree.size(), true);
	queue<int> q;
	save[0] = false;
	int num, f;
	for (int i = 0; i < nodes.size(); i++) {
		num = nodes[i];
		q.push(num);
		save[num] = false;
		while (!q.empty()) {
			f = q.front();
			q.pop();
			for (int n : tree[f]) {
				if (n == 1) {
					return num;
				}
				if (save[n] == true) {
					save[n] = false;
					q.push(n);
				}
			}
		}
	}
}

//1부터내려가면서 각노드의 부모를 저장하는 함수
vector<int> set_parent_node(vector<vector<int>>& tree) {
	int len = tree.size();
	vector<int> res(len, -1);
	queue<int> q;
	q.push(1);
	int num;
	while (!q.empty()) {
		num = q.front();
		q.pop();
		for (int n : tree[num]) {
			if (res[n] == -1) {
				res[n] = num;
				q.push(n);
			}
		}
	}
	return res;
}

int main() {
	//빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<vector<int>> tree(N+1);
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vector<int> res = set_parent_node(tree);
	for (int i = 2; i <= N; i++) {
		cout << res[i] << "\n";
	}
}