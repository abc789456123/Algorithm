#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

pair < int, int> find_2dim(const vector<vector<bool>> &farm) {
	pair <int, int> res;
	for (int i = 0;i < farm.size();i++) {
		for (int j = 0;j < farm[i].size();j++) {
			if (farm[i][j] == true) {
				return { i, j };
			}
		}
	}
	return {-1, -1};
}

int dfs(vector<vector<bool>> &farm, int M, int N) {
	int cnt = 0;
	pair<int, int> p;
	queue <pair<int, int>> q;

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	int a, b;

	p = find_2dim(farm);

	//true 위치 탐색 후 q에 넣기
	//..true 위치 탐색 none 뜰때까지 위 반복
	while (1) {
		p = find_2dim(farm);
		if (p.first == -1) break;

		q.push(p);
		farm[p.first][p.second] = false;

		cnt++;
		//dfs돌리기
		while (!q.empty()) {
			p = q.front();
			for (int i = 0;i < 4;i++) {
				a = p.first + dx[i];
				b = p.second + dy[i];
				if (a >= 0 && b >= 0 && a < M && b < N && farm[a][b] == true) {
					q.push({ a, b });
					farm[a][b] = false;
				}
			}
			q.pop();
		}

	}

	return cnt;
}

int main()
{
	int T;
	int M, N, K;
	int a, b;
	int cnt;
	vector<int> res;
	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> M >> N >> K;
		vector<vector <bool>> farm (M, vector<bool>(N, false));
		for (int i = 0;i < K; i++) {
			cin >> a >> b;
			farm[a][b] = true;
		}
		cnt = dfs(farm, M, N);
		res.push_back(cnt);
	}

	for (int i = 0;i < T;i++) {
		cout << res[i] << "\n";
	}

}

