#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <list>
#include <tuple>

using namespace std;

int N, M, X, S, R, C, L, K;
vector<vector<vector<int>>> result(1000, vector<vector<int>>(1000, vector<int>(2, INT_MAX)));

// (N-1, M-1)에서 stop
void func(const vector<string>& v) {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	tuple<int, int, int> tu;
	while (!q.empty()) {
		tu = q.front();
		q.pop();
		int a = get<0>(tu), b = get<1>(tu), broken = get<2>(tu);

		for (int i = 0; i < 4; i++) {
			int x = a + dx[i];
			int y = b + dy[i];
			if (x < 0 || x >= N || y < 0 || y >= M)continue;
			if (v[x][y] == '0' && result[x][y][broken] > result[a][b][broken]+1) {
				result[x][y][broken] = result[a][b][broken] + 1;
				q.push({ x, y, broken });
			}
			else if (v[x][y] == '1' && broken == 0 &&
				result[x][y][1] > result[a][b][broken] + 1) {
				result[x][y][1] = result[a][b][broken] + 1;
				q.push({ x, y, 1 });
			}
		}
	}


}

int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> N >> M;
	vector<string> v(N);
	result[0][0][0] = 1;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// 출력
	func(v);
	if (result[N - 1][M - 1][0] == INT_MAX && result[N - 1][M - 1][1] == INT_MAX) {
		cout << -1;
	}
	else {
		cout << min(result[N - 1][M - 1][0], result[N - 1][M - 1][1]);
	}


	return 0;
}

