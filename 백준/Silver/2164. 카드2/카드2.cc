#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	queue<int> q;
	for (int i = 0;i < N;i++) {
		q.push(i + 1);
	}
	int res=0;
	while (!q.empty()) {
		res = q.front();
		q.pop();
		if (!q.empty()) {
			res = q.front();
			q.pop();
			if (!q.empty()) {
				q.push(res);
			}
		}
	}
	cout << res;
}
