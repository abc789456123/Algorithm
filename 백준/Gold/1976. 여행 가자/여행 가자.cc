#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

int N, M, S, R, C;
bool dfs(const vector<vector<int>>& v, int start, int end) {
	queue<int> q;
	vector<bool> save(N + 1, true);
	q.push(start);
	save[start] = false;

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (num == end) {
			return true;
		}
		for (int i = 1; i <= N; i++) {
			if (v[num][i] == 1 && save[i]) {
				q.push(i);
				save[i] = false;
			}
		}
	}
	return false;
}

bool func(const vector<vector<int>>& v, queue<int>& plan) {
	int pre = plan.front();
	plan.pop();
	while (!plan.empty()) {
		int des = plan.front();
		plan.pop();
		if (dfs(v, pre, des)) {
			pre = des;
		}
		else {
			return false;
		}
	}
	return true;
}
int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> N >> M;
	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> v[i][j];
		}
	}
	queue <int> plan;
	int num;
	for (int i = 0; i < M;i++) {
		cin >> num;
		plan.push(num);
	}

	if (func(v, plan)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}


	// 출력
	return 0;
}
