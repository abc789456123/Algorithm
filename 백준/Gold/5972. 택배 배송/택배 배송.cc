#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits> // MAX_INT 사용

using namespace std;

int N = 0, M = 0;

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N >> M;
	int a, b, c;
	vector<vector<pair<int, int>>> v(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	// 로직
	// 최단거리 테이블
	// 현서는 헛간 1에 있고 농부 찬홍이는 헛간 N에 있습니다.
	vector<int> table(N + 1, INT_MAX);
	table[1] = 0;
	queue<int> q;
	pair<int, int> p;
	q.push(1);
	int index;
	int destination, cost;
	while (!q.empty()) {
		index = q.front();
		q.pop();
		for (int i = 0; i < v[index].size(); i++) {
			p = v[index][i];
			destination = p.first;
			cost = p.second;
			if (table[index] + cost < table[destination]) {
				table[destination] = table[index] + cost;
				q.push(destination);
			}
		}
	}

	// 출력
	cout << table[N];

	return 0;
}
