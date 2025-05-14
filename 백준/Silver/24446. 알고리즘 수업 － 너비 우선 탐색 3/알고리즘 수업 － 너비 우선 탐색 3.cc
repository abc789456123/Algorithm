#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//24446 알고리즘 수업 - 너비 우선 탐색

int main()
{
	int N, M, R;
	cin >> N >> M >> R;
	vector<vector<int>> graph(N+1, vector<int>());
	vector<int> d(N+1, -1);
	int a, b;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int> q;
	q.push(R);
	d[R] = 0;
	while (!q.empty()) {
		a = q.front();
		for (int i : graph[a]) {
			if (d[i] == -1) {
				d[i] = d[a] + 1;
				q.push(i);
			}
		}
		q.pop();
	}

	for (int i = 1;i < d.size();i++) {
		cout << d[i] << "\n";
	}

}

