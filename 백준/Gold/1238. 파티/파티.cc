#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <list>

using namespace std;

int N, M, X, S, R, C;

int func(const vector<vector<pair<int, int>>>& v, int start, int end) {
	vector<int> save(N + 1, INT_MAX);
	save[start] = 0;

	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({ 0,start });

	while (save[end]==INT_MAX) {
		pair<int, int> p = q.top();	//cost, destination
		save[p.second] = p.first;
		q.pop();
		for (int i = 0; i < v[p.second].size(); i++) {
			pair<int, int> p1 = v[p.second][i];
			if(save[p1.second] == INT_MAX)	q.push({ p1.first + p.first, p1.second });
		}
	}

	return save[end];
}

int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> N >> M >> X;
	
	vector<vector<pair<int, int>>> v(N + 1);

	int start, end, cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		v[start].push_back({ cost, end });
	}

	int res = 0;
	
	// 최대 거리 계산
	for (int i = 1; i <= N; i++) {
		if (i == X)continue;
		res = max(res, func(v, i, X) + func(v, X, i));
	}

	// 출력
	cout << res;

	return 0;
}

