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

	vector<vector<int>> v(N, vector<int>(M, -1));
	vector<vector<bool>> save(N, vector<bool>(M, false));
	string str;

	for (int i = 0;i < N;i++) {
		cin >> str;
		for (int j = 0;j < M;j++) {
			v[i][j] = str[j] - '0';
			if (v[i][j] == 1)	save[i][j] = true;
		}
	}

	//N-1, M-1 위치로 가는 최소 거리

	queue <pair<int, int>> q;
	pair<int, int> p = { 0, 0 };
	q.push(p);
	save[0][0] = false;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	int a;
	int x, y;

	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			x = p.first + dx[i];
			y = p.second + dy[i];
			if (x >= 0 && x < N && y >= 0 && y < M && save[x][y] == true) {
				q.push({ x,y });
				v[x][y] = v[p.first][p.second] + 1;
				save[x][y] = false;
			}
		}

	}

	cout << v[N - 1][M - 1];

	return 0;
}


