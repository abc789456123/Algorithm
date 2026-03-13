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

int N, M, L, R, C;

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	string str;
	cin >> str;
	int a_cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a')a_cnt++;
	}
	int len = str.size();
	str = str + str;
	int ans = INT_MAX;
	for (int i = 0; i < len; i++) {
		int b_cnt = 0;
		for (int j = i; j < i + a_cnt; j++) {
			if (str[j] == 'b')b_cnt++;
		}
		if (b_cnt < ans)ans = b_cnt;
	}

	// 출력
	cout << ans;

	return 0;
}