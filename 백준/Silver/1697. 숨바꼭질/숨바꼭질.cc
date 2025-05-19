#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

vector<int> move(int k) {
	return { k - 1, k + 1, 2 * k };
}

int bfs(int* arr, int N, int M) {
	queue<int> q;
	q.push(N);
	int a;

	while (!q.empty()) {
		a = q.front();
		q.pop();
		for (int i : move(a)) {
			if (i >= 0 && i <= 100000 && arr[i] == 0) {
				q.push(i);
				arr[i] = arr[a] + 1;
				if (i == M) {
					return arr[i];
				}
			}
		}
	}
	return arr[M];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int* arr=new int[100001]();
	arr[N] = 1;

	cout << bfs(arr, N, M)-1;
	

	return 0;
}


