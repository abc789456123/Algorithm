#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	vector<vector<bool>> save(N, vector<bool>(M, true));

	pair<int, int> p;

	for (int i = 0; i < N;i++) {
		for (int j = 0;j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				p = { i,j };
			}
			if (v[i][j] == 0) {
				save[i][j] = false;
			}
		}
	}

	queue<pair<int, int>> q;

	q.push(p);

	v[p.first][p.second] = 0;
	save[p.first][p.second] = false;

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int x = 0, y = 0;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			x = p.first + dx[i];
			y = p.second + dy[i];

			if (x >= 0 && x < N && y >= 0 && y < M && v[x][y] != 0 && save[x][y] == true) {
				v[x][y] = v[p.first][p.second] + 1;
				save[x][y] = false;
				q.push({ x,y });
			}
		}
	}

	for (int i = 0; i < N;i++) {
		for (int j = 0;j < M; j++) {
			if (save[i][j] == true) {
				v[i][j] = -1;
			}
		}
	}


	for (int i = 0; i < N;i++) {
		for (int j = 0;j < M; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
