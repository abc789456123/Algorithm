#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <list>

using namespace std;

int N, M, S, R, C;


int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> N;
	vector<int> numbers(N+1,0);
	vector<int> dp(N+1,1);
	for (int i = 1; i <= N; i++) {
		cin >> numbers[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (numbers[j] < numbers[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int num = *max_element(dp.begin(), dp.end());
    
	// 출력
	cout << N - num;

	return 0;
}