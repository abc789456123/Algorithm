#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr;
int N;
int res = 0;

// len 수열의 길이, index 현재 체크중인 arr의 위치, max_num 현재 수열의 최대값
void back_tracking_func(int len, int index, int max_num) {
	res = max(res, len);
	for (int i = index; i < N; i++) {
		if (arr[i] > max_num) {
			back_tracking_func(len+1, i+1,arr[i]);
		}
	}
}

int dp_func() {
	vector<int> dp(N, 1);
	int num = 1;
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j]+1, dp[i]);
			}
		}
		num = max(dp[i], num);
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)cin >> arr[i];

	res = dp_func();
	cout << res;
}