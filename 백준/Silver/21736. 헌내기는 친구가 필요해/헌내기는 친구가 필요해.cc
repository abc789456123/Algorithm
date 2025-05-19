#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string str;
	vector<vector<char>> v(N, vector<char> (M));
	pair<int, int> p;

	for (int i = 0;i < N;i++) {
		cin >> str;
		for (int j = 0;j < M;j++) {
			v[i][j] = str[j];
			if (str[j] == 'I') {
				p = { i, j };
			}
		}
	}

	queue <pair<int, int>> q;
	q.push(p);
	v[p.first][p.second] = 'X';

	int res = 0;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int x, y;

	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			x = p.first + dx[i];
			y = p.second + dy[i];
			if (x >= 0 && x < N && y >= 0 && y < M && v[x][y] != 'X') {
				q.push({ x,y });
				if (v[x][y] == 'P') res++;
				v[x][y] = 'X';
			}
		}
	}

	if (res != 0)cout << res;
	else cout << "TT";

	return 0;
}


