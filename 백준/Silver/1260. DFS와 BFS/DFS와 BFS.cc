#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

vector<int> bfs(const vector<vector<int>> &v, int V, int N) {
	vector<bool> save(N + 1, true);
	queue <int> q;
	vector<int> res;
	q.push(V);
	save[V] = false;
	res.push_back(V);
	int a;
	while (!q.empty()) {
		a = q.front();
		for (int i : v[a]) {
			if (save[i] == true) {
				q.push(i);
				res.push_back(i);
				save[i] = false;
			}
		}
		q.pop();
	}
	return res;
}

vector<int> dfs(const vector<vector<int>> &v, int V, int N) {
	vector<bool> save(N + 1, true);
	stack <int> stk;
	vector<int> res;
	stk.push(V);
	int a;
	while (!stk.empty()) {
		a = stk.top();
		stk.pop();
		if (save[a] == false) {
			continue;
		}

		res.push_back(a);
		save[a] = false;

		for (int i = v[a].size() - 1;i >= 0;i--) {
			stk.push(v[a][i]);
		}
	}
	return res;
}

int main()
{
	int M, N, V;
	cin >> N >> M >> V;
	vector<vector<int>> v(N + 1, vector<int>());
	int a, b;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (vector<int> &v1 : v) {
		sort(v1.begin(), v1.end());
	}
	vector<int> resd = dfs(v, V, N);
	vector<int> resb = bfs(v, V, N);
	for (int i = 0;i < resd.size();i++) {
		cout << resd[i] << " ";
	}
	cout << "\n";
	for (int i = 0;i < resb.size();i++) {
		cout << resb[i] << " ";
	}
}

