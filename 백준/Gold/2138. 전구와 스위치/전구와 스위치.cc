#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits> // INT_MAX 사용
#include <cmath>

using namespace std;

int N, L, R, C;
uint32_t v[100002] = {};
uint32_t ans[100002] = {};

// i-1, i, i+1의 세 개의 전구의 상태를 바꾸는 함수
void flip(uint32_t a[], int n) {
	if (n >= 1 && n <= N) {
		for (int i = n - 1; i <= n + 1; i++) {
			a[i] ^= 1u;
		}
	}
}

// N개의 전구들이 만들고자 하는 상태가 됐는지 확인하는 함수
bool check(uint32_t a[]) {
	for (int i = 1; i <= N; i++) {
		if (a[i] != ans[i]) {
			return false;
		}
	}
	return true;
}

// 전구를 만들고자 하는 상태로 만들기 위해 몇번 눌러야 하는지 알아내는 함수
int func(bool pressFirst) {
	static uint32_t cur[100002];
	for (int i = 0; i <= N + 1; ++i) cur[i] = v[i];
	int res = 0;
	if (pressFirst) { 
		flip(cur, 1);
		res++; 
	}
	for (int i = 1; i < N; i++) {
		if (cur[i] != ans[i]) {
			flip(cur, i + 1);
			res++;
		}
	}
	
	return (check(cur)) ? res : INT_MAX;
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N;
	string sv, san;
	cin >> sv;
	cin >> san;
	for (int i = 1; i <= N; i++) {
		if (sv[i - 1] == '1') {
			v[i] = 1;
		}
		else {
			v[i] = 0;
		}
		v[i] &= 1u;
	}
	for (int i = 1; i <= N; i++) {
		if (san[i - 1] == '1') {
			ans[i] = 1;
		}
		else {
			ans[i] = 0;
		}
		ans[i] &= 1u;
	}
	
	// 출력
	int res = min(func(true), func(false));
	if (res == INT_MAX) cout << "-1";
	else cout << res;

	return 0;
}
