#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>
//
using namespace std;
int check(long long* v, long long len, int K) {
	int res = 0;
	for (int i = 0;i < K;i++) {
		res += v[i] / len;
	}
	return res;
}

long long binary_search(long long* v, long long left, long long right, int K, int N) {
	//랜선목록, 최소, 최대, 랜선개수, 목표개수
	long long mid = left + (right - left) / 2;
	if (left > right) {
		return right;
	}
	if (check(v, mid, K) < N) {
		return binary_search(v, left, mid - 1, K, N);
	}
	else {
		return binary_search(v, mid + 1, right, K, N);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, N;

	cin >> K >> N;

	long long* v = new long long[K]();
	for (int i = 0;i < K;i++) {
		cin >> v[i];
	}

	long long right = *max_element(v, v + K);

	long long test = binary_search(v, 1, right, K, N);

	cout << test;

	delete[] v;
	return 0;
}
