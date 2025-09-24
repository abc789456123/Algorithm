#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int MAX = 2147483647;

bool check_same(vector<int>v1, vector<int>v2) {
	if (v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2]) {
		return true;
	}
	return false;
}

int main() {
	int N, K;
	cin >> N >> K;
	int num, g, s, b;
	vector<vector<int>> rank(N, vector<int>(4, 0));
	for (int i = 0; i < N; i++) {
		cin >> rank[i][3] >> rank[i][0] >> rank[i][1] >> rank[i][2];
	}
	sort(rank.begin(), rank.end());

	int res, j;
	for (int i = 0; i < N; i++) {
		if (rank[i][3] == K) {
			res = i + 1;
			j = i;
			while (j>0&&check_same(rank[j], rank[j - 1])) {
				res--;
				j--;
			}
		}
	}

	cout << res;
}