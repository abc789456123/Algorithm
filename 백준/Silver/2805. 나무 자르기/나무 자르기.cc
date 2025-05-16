#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

long long cut(int* tree, int H, int N) {
	long long res = 0;
	for (int i = 0;i < N;i++) {
		if (tree[i] > H) {
			res += tree[i] - H;
		}
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
	int* tree = new int[N]();

	for (int i = 0;i < N;i++) {
		cin >> tree[i];
	}

	//정렬
	sort(tree, tree + N);

	int tot = 0;
	int bottom = 0, top = tree[N-1];
	int mid;
	long long ctree;
	long long res = 0;

	while (bottom <= top) {
		mid = (top + bottom) / 2;
		ctree = cut(tree, mid, N);
		if (ctree >= M) {
			res = mid;
			bottom = mid+1;
		}
		else {
			top = mid-1;
		}
	}

	cout << res;

	delete[] tree;
	return 0;
}

