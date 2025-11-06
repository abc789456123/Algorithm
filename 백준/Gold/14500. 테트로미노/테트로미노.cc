#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits> // INT_MAX 사용
#include <cmath>

using namespace std;

int N, M, L, R, C;
int max_res = 0;

// v에서 4칸짜리 테트로미노 형태로 칸을 더할 때 최댓값을 구하는 함수

// a, b는 기록점, index는 몇번째 칸인지 기록
void func(const vector<vector<int>>& v, vector<vector<bool>>& save, 
	int a, int b, int index, int res) {
	res += v[a][b];
	save[a][b] = false;

	if (index == 4) {
		if (res > max_res) {
			max_res = res;
		}
		save[a][b] = true;
		return;
	}

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int x, y;

	for (int i = 0; i < 4; i++) {
		x = a + dx[i];
		y = b + dy[i];
		// 범위 체크
		if (x >= 0 && x < N && y >= 0 && y < M) {
			if (save[x][y]) {
				func(v, save, x, y, index + 1, res);
			}
		}
	}
	save[a][b] = true;
}

void chcek_T(const vector<vector<int>>& v, int a, int b) {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	vector<int> t;
	
	for (int i = 0; i < 4; i++) {
		int x = a + dx[i];
		int y = b + dy[i];
		// 범위 체크
		if (x >= 0 && x < N && y >= 0 && y < M) {
			t.push_back(v[x][y]);
		}
	}
	if (t.size() >= 3) {
		sort(t.rbegin(), t.rend());
		int res = v[a][b] + t[0] + t[1] + t[2];
		if (res > max_res) {
			max_res = res;
		}
	}
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N >> M;
	vector<vector<int>> v;
	vector<vector<bool>> save;
	v.resize(N, vector<int>(M, 0));
	save.resize(N, vector<bool>(M, true));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			func(v, save, i, j, 1, 0);
			chcek_T(v, i, j);
		}
	}
	// 출력
	cout << max_res;
	return 0;
}