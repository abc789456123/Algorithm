#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <list>

using namespace std;

int N, M, X, S, R, C, L, K;
int func(vector<pair<int, int>>& v, int x, int y) {
	int res = 0;
	//범위 : x~x+L, y~y+L

	for (pair<int, int> p : v) {
		if (p.first >= x && p.first <= x + L && p.second >= y && p.second <= y + L) res++;
	}
	return res;
}

int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> N >> M >> L >> K;
	vector<pair<int, int>> meteor(K);

	for (int i = 0; i < K; i++) {
		cin >> meteor[i].first >> meteor[i].second;
	}
	int res = 0;

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			pair<int, int> p;
			p.first = meteor[i].first;
			p.second = meteor[j].second;
			res = max(res, func(meteor, p.first, p.second));
		}
	}

	// 출력
	cout << K - res;

	return 0;
}

