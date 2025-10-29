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

int N, L, R;

// 인구이동이 발생하면 true를 반환하는 함수
// 인구이동 발생 결과를 v에 레퍼런스로 반영한다
bool func(vector<vector<int>>& v) {
	vector<vector<int>> save(N, vector<int>(N, -1));
	queue<pair<int, int>> q;
	pair<int, int> p;
	int zone = 0;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	int x, y, a, b;

	vector<vector<pair<int, int>>> zonelist;
	vector<pair<int, int>> list;

	bool flag = false;

	// 모든 국경 개방하고 연합으로 구분하는 로직
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (save[i][j] == -1) {	// 아직 주변 국가와 국경 체크가 되지 않은 경우
				// 1번째 연합부터 탐색시작
				zone++;
				p = { i, j };
				q.push(p);
				save[i][j] = zone;
				list.push_back({ i,j });
				// zone번째 연합에 들어갈 모든 국가를 탐색
				while (!q.empty()) {
					p = q.front();
					q.pop();
					a = p.first;
					b = p.second;
					// 사방에 인구이동 가능한지 체크
					for (int k = 0; k < 4; k++) {
						x = a + dx[k];
						y = b + dy[k];
						// 범위 체크
						if (x >= 0 && x < N && y >= 0 && y < N && save[x][y] == -1) {
							// 인구 이동 가능 여부 체크
							if (abs(v[a][b] - v[x][y]) >= L && abs(v[a][b] - v[x][y]) <= R) {
								// 인구 이동 가능한 경우
								save[x][y] = zone;
								q.push({ x,y });
								list.push_back({ x,y });
							}
						}
					}
				}
				zonelist.push_back(list);
				list.clear();
			}
		}
	}
	int alltile = N * N;
	// 한개 이상의 연합이 생성되어 인구이동이 발생할 경우
	if (zone != alltile) flag = true;
	// 구분된 연합으로 인구 이동 발생시키는 로직
	for (int i = 0; i < zonelist.size(); i++) {
		list = zonelist[i];
		int cnt = list.size();
		int sum = 0;
		for (int j = 0; j < cnt; j++) {
			x = list[j].first;
			y = list[j].second;
			sum += v[x][y];
		}
		int num = sum / cnt;
		for (int j = 0; j < cnt; j++) {
			x = list[j].first;
			y = list[j].second;
			v[x][y] = num;
		}
	}

	return flag;
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N >> L >> R;
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	// 출력
	int res = 0;
	while (func(v)) {
		res++;
	}
	cout << res;

	return 0;
}
