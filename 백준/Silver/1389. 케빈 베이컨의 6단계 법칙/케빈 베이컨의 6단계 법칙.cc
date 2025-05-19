#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

//start의 케빈베이컨 수 구하기
int get_num(const vector<vector<int>>& v, int start) {
	int N = v.size();
	vector<int> save(N + 1, -1);
	queue<int> q;
	q.push(start);
	save[start] = 0;
	int a;
	while (!q.empty()) {
		a = q.front();
		q.pop();
		for (int i : v[a]) {
			if (save[i] == -1) {
				save[i] = save[a] + 1;
				q.push(i);
			}
		}
	}
	int res = 0;
	for (int i = 1;i < N;i++) {
		res += save[i];
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N + 1, vector<int>());
	
	int a, b;

	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int num = get_num(v, 1);
	int res = 1;
	for (int i = 2;i <= N;i++) {
		if (num > get_num(v, i)) {
			num = get_num(v, i);
			res = i;
		}
	}

	cout << res;

	return 0;
}


