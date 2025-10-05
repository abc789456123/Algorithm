#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int MAX_INT = 2147483647;
int N, M;
int arr[100001]{};

vector<int> move(int x) {
	return { x + 1, x - 1, 2*x };
}

int main() {
	//빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	fill_n(arr, 100001, MAX_INT);
	arr[N] = 0;
	// arr[M] 이 목표
	
	queue <int> q;
	q.push(N);
	int x, dx;
	vector<int> movex;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		movex = move(x);
		for (int i = 0; i < 3; i++) {
			dx = movex[i];
			if (dx >= 0 && dx <= 100000 && arr[dx]>arr[x]) {
				if (i < 2) arr[dx] = arr[x] + 1;
				if (i == 2) arr[dx] = arr[x];
				q.push(dx);
			}
		}
	}

	cout << arr[M];
}