#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> v((N + 1), vector<int>());
	vector<bool> save(N + 1, false);
	save[0] = true;
	int a, b;

	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		v.at(a).push_back(b);
		v.at(b).push_back(a);
	}

	vector<bool>::iterator start = find(save.begin(), save.end(), false);
	queue<int> q;
	int index;
	int res = 0;

	while (start != save.end()) {
		res++;
		index = start - save.begin();
		q.push(index);
		save[index] = true;
		while (!q.empty()) {
			a = q.front();
			q.pop();
			for (int i = 0;i < v[a].size();i++) {
				b = v[a][i];
				if (save[b] == false) {
					q.push(b);
					save[b] = true;
				}
			}
		}

		start = find(save.begin(), save.end(), false);
	}
	cout << res;
	return 0;
}

