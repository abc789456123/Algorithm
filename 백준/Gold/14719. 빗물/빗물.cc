#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <stack>

using namespace std;

int N, M;
/*
입력
첫 번째 줄에는 2차원 세계의 세로 길이 H과 2차원 세계의 가로 길이 W가 주어진다. (1 ≤ H, W ≤ 500)
두 번째 줄에는 블록이 쌓인 높이를 의미하는 0이상 H이하의 정수가 2차원 세계의 맨 왼쪽 위치부터 차례대로 W개 주어진다.
따라서 블록 내부의 빈 공간이 생길 수 없다. 또 2차원 세계의 바닥은 항상 막혀있다고 가정하여도 좋다.

출력
2차원 세계에서는 한 칸의 용량은 1이다. 고이는 빗물의 총량을 출력하여라.
빗물이 전혀 고이지 않을 경우 0을 출력하여라.
*/

// 두 true 사이의 false 개수 카운팅
int func(vector<bool> v) {
	int res = 0, cnt = 0;
	bool flag = false;
	for (int i = 0; i < v.size(); i++) {
		// 최초 벽을 만나는 순간
		if (v[i] && !flag) {
			flag = true;
		}
		// 이후 false(빈공간)를 만나는 순간
		else if (!v[i] && flag) {
			cnt++;
		}
		// 이후 ture(벽)를 만나는 순간
		else if (v[i] && flag) {
			res += cnt;
			cnt = 0;
		}
	}
	return res;
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N >> M;
	int block;
	vector<vector<bool>> world(M, vector<bool>(N + 1, false));
	for (int i = 0; i < M; i++) {
		cin >> block;
		for (int j = block; j >= 0; j--) {
			world[i][j] = true;
		}
	}

	// 로직
	int res = 0;
	// 가장 높은 위치 N부터 위에서 아래로 내려와
	// 블록이 있으면 1이고 블록이 없으면 0이야
	// 1사이에 0이 있을때 사이에 있는 0의 개수를 결과값에 추가해
	// 예를 들어 100100 이런식으로 오면 2를 추가
	vector<bool> v(M);
	for (int i = N; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			v[j] = world[j][i];
		}
		res += func(v);
	}

	// 출력
	cout << res;

	return 0;
}
