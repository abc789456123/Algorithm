#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>

using namespace std;

pair<int, int> find_start(const vector<string>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size();j++) {
			if (v[i][j] != 'o') return { i, j };
		}
	}
	return { -1, -1 };
}

int bfs(vector<string>& v) {
	queue<pair<int, int>> q;
	pair<int, int> p = find_start(v);
	if (p.first == -1) return 0;
	char top = v[p.first][p.second];
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int x, y;
	int N = v.size();
	int res = 0;

	while (p.first != -1) {
		res++;
		p = find_start(v);
		if (p.first == -1) break;
		top = v[p.first][p.second];
		v[p.first][p.second] = 'o';
		q.push(p);
		while (!q.empty()) {
			p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				x = p.first + dx[i];
				y = p.second + dy[i];
				if (x >= 0 && x < N && y >= 0 && y < N && v[x][y] == top) {
					v[x][y] = 'o';
					q.push({ x, y });
				}
			}
		}

		p = find_start(v);
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<string> v(N);
	vector<string> vRG(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		vRG[i] = v[i];
		for (char &c : vRG[i]) {
			if (c == 'R') c = 'G';
		}
	}
	cout << bfs(v) << " " << bfs(vRG);
}

