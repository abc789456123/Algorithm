#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력 받기 
	int N, M;
	cin >> N >> M;
	vector<vector<int>> tomato(M, vector<int>(N));
	vector<vector<bool>> save(M, vector<bool>(N, false));
	int a;
	queue<pair<int, int>> q;

	//토마토 상태 입력 받기
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			cin >> a;
			tomato[i][j] = a;

			//익은 토마토 시작지점에 저장
			if (a == 1) {
				q.push({ i, j });
			}
		}
	}

	int nx = 0;
	int ny = 0;
	int dx[4] = { 0, -1, 0, 1 };
	int dy[4] = { -1, 0, 1, 0 };

	//BFS
	while (!q.empty()) {
		nx = q.front().first;
		ny = q.front().second;
		save[nx][ny] = true;
		for (int i = 0;i < 4;i++) {
			//경로이탈 방지
			if (nx + dx[i] >= 0 && nx + dx[i] < M && ny + dy[i] >= 0 && ny + dy[i] < N) {
				//가본적 없는 곳이면 토마토 상태 바꾸기
				if (save[nx + dx[i]][ny + dy[i]] == false && tomato[nx + dx[i]][ny + dy[i]] == 0) {
					q.push({ nx + dx[i],ny + dy[i] });
					tomato[nx + dx[i]][ny + dy[i]] = tomato[nx][ny]+1;
				}
			}
		}
		q.pop();
	}

	int day = 0;
	int mday;
	//토마토 상태 확인
	for (int i = 0;i < M;i++) {
		//가장 마지막에 익은 토마토가 몇일차에 익었는지 저장
		mday = *max_element(tomato[i].begin(), tomato[i].end());
		if (mday > day) day = mday;

		//안익은 토마토 있는지 확인
		for (int j = 0;j < N;j++) {
			a = tomato[i][j];
			//안익은 토마토 있으면 -1 출력
			if (a == 0) {
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	cout << day - 1;
	return 0;
}
