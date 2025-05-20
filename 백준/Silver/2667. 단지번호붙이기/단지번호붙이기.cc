#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

//전체를 순회하며 1의 위치를 함수, 없을 경우 -1리턴
pair<int, int> search(const vector<vector<int>>& v) {
	for (int i = 0;i < v.size();i++) {
		for (int j = 0;j < v[i].size();j++) {
			if (v[i][j] == 1) {
				return { i, j };
			}
		}
	}
	return { -1, -1 };
}

//시작 위치에서 모든 1을 0으로 바꾸며 바꾼 요소의 수를 출력하는 함수
int bfs(vector<vector<int>>& v, pair<int, int> p) {
	int res;
	queue<pair<int, int>> q;
	q.push(p);
	v[p.first][p.second] = 0;
	res = 1;

	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	int x, y;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			x = p.first + dx[i];
			y = p.second + dy[i];
			if (x >= 0 && x < v.size() && y >= 0 && y < v.size() && v[x][y] == 1) {
				q.push({ x,y });
				v[x][y] = 0;
				res++;
			}
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> v((N), vector<int>());
	string str;
	int a;

	for (int i = 0;i < N;i++) {
		cin >> str;
		for (char c : str) {
			a = c - '0';
			v[i].push_back(a);
		}
	}

	//전체를 순회하며 1의 위치를 함수, 없을 경우 -1리턴
	pair<int, int> p = search(v);

	vector<int> res;
	int b;
	int cnt = 0;
	//시작 위치에서 모든 1을 0으로 바꾸며 바꾼 요소의 수를 출력하는 함수
	while (p.first != -1 && p.second != -1) {
		cnt++;
		b = bfs(v, p);
		res.push_back(b);
		p = search(v);
	}

	sort(res.begin(), res.end());

	cout << cnt << "\n";
	for (int i : res) {
		cout << i << "\n";
	}

	return 0;
}
