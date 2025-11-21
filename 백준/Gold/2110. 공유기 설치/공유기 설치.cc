#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, S, R, C;

// 최소거리를 d로 했을때 설치가 가능한지 체크하는 함수
bool func(const vector<int>& v, int d) {
	int cnt = 1;
	int num = v[0];
	for (int i = 1; i < N; i++) {
		if (v[i] >= num + d) {
			num = v[i];
			cnt++;
		}
	}
	if (cnt >= C) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> N >> C;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int min = 1, max = v[N - 1] - v[0];
	int res;
	while (min <= max) {
		int mid = (min + max) / 2;
		if (func(v, mid)) {
			res = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}

	// 출력
	cout << res;
	return 0;
}
