#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N = 1;

// 0,0부터 N-1,N-1까지 가는데 드는 최소값을 구하는 함수
int func(vector<vector<int>>& v) {
	int len = v.size();
	vector<vector<int>> save(len, vector<int>(len, INT_MAX));
	pair<int, int> p;
	queue<pair<int, int>> q;
	p = { 0,0 };
	q.push(p);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	save[0][0] = v[0][0];

	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = p.first + dx[i];
			int y = p.second + dy[i];
			// 범위 체크
			if (x >= 0 && x < len&&y >= 0 && y < len) {
				// 최소 경로 체크
				if (save[x][y] > save[p.first][p.second] + v[x][y]) {
					q.push({ x,y });
					save[x][y] = save[p.first][p.second] + v[x][y];
				}
			}
		}
	}

	return save[len - 1][len - 1];
}

int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	vector<vector<int>> v;
	vector<int> res;
	while (true) {
		cin >> N;
		if (N == 0) break;
		v.assign(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> v[i][j];
			}
		}
		res.push_back(func(v));
	}

	// 출력
	for (int i = 0; i < res.size(); i++) {
		cout << "Problem " << i + 1 << ": " << res[i] << "\n";
	}
}
