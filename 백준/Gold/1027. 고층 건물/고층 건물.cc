#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

int N, M, S, R, C;
int result(int dx, int dy, int x) {
	return x * (dy / dx);
}
// index위치에서 보이는 빌딩의 개수
int func(const vector<double>& v, double index) {
	int len = v.size();
	if (len == 1) return 0;
	else if (len == 2) return 1;
	else if (len == 3)return 2;
	long double grad = 0, max_grad = INT_MIN, min_grad = INT_MAX;
	double left = index - 1, right = index + 1;
	int res = 0;

	while (left >= 0) {
		// left위치의 빌딩이 보이는지 체크
		grad = (v[index] - v[left]) / (index - left);
		if (grad < min_grad) {
			min_grad = grad;
			res++;
		}
		left--;
	}

	while (right < N) {
		// right위치의 빌딩이 보이는지 체크
		grad = (v[index] - v[right]) / (index - right);
		if (grad > max_grad) {
			max_grad = grad;
			res++;
		}
		right++;
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
	cin >> N;
	vector<double> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		int cnt = func(v, (double)i);
		res = max(res, cnt);
	}
	// 출력
	cout << res;
	return 0;
}
