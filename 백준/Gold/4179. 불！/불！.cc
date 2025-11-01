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

int N, L, R, C;

// 지훈이가 탈출까지 걸리는 시간을 반환하는 함수
// 탈출 불가능이면 -1 반환
int func(vector<string> v) {
	pair<int, int> jp;
	pair<int, int> fp;
	// 지훈의 이동 경로
	queue<pair<int, int>> jq;
	// 불의 이동 경로
	queue<pair<int, int>> fq;
	vector<vector<int>> save(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (v[i][j] == 'J') {
				jq.push({ i,j });
				save[i][j] = 1;
			}
			else if (v[i][j] == 'F') {
				fq.push({ i,j });
				save[i][j] = -1;
			}
			else if (v[i][j] == '#') {
				save[i][j] = -1;
			}
		}
	}
	// 이미 지훈이가 탈출 직전인 경우 체크
	jp = jq.front();
	if (jp.first == 0 || jp.first == R - 1 || jp.second == 0 || jp.second == C - 1) {
		return 1;
	}

	// save에서 1이 음수자리를 피하며 행렬의 가장자리로 이동했을때 최소값을 반환
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int x, y;

	// 불이 이동
	while (!fq.empty()) {
		fp = fq.front();
		fq.pop();

		for (int i = 0; i < 4; i++) {
			x = fp.first + dx[i];
			y = fp.second + dy[i];
			// 범위 이탈 체크
			if (x >= 0 && x < R && y >= 0 && y < C) {
				if (save[x][y] == 0) {
					fq.push({ x,y });
					save[x][y] = save[fp.first][fp.second] - 1;
				}
			}
		}
	}

	// 지훈이 이동
	while (!jq.empty()) {
		jp = jq.front();
		jq.pop();
		
		for (int i = 0; i < 4; i++) {
			x = jp.first + dx[i];
			y = jp.second + dy[i];
			// 범위 이탈 체크
			if (x >= 0 && x < R && y >= 0 && y < C) {
				// 불이 지나가지 않은 공간일 경우
				if (save[x][y] == 0) {
					jq.push({ x,y });
					save[x][y] = save[jp.first][jp.second] + 1;
					if (x == 0 || x == R - 1 || y == 0 || y == C - 1) {
						return save[x][y];
					}
				}
				// 불이 지나가는 경우 불보다 빨리 지나가야함
				// 음수값보다 현재가 절댓값이 작으면 덮어씌울 수 있음
				if (save[x][y] < 0) {
					if (abs(save[jp.first][jp.second]) + 1 < abs(save[x][y])) {
						jq.push({ x,y });
						save[x][y] = save[jp.first][jp.second] + 1;
						if (x == 0 || x == R - 1 || y == 0 || y == C - 1) {
							return save[x][y];
						}
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> R >> C;
	string s;
	vector<string> v;
	for (int i = 0; i < R; i++) {
		cin >> s;
		v.push_back(s);
	}

	// 출력
	if (func(v) == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << func(v);
	}

	return 0;
}
