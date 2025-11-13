#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, S;
/*
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 
이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 
가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.
*/

// 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중
// 가장 짧은 것의 길이를 구하는 함수
// 길이는 최소 2일것을 가정
int func(const vector<int>& v) {
	int min_res = INT_MAX;
	int left = 0, right = 1;
	int sum = v[0] + v[1];
	int res = 2;

	while (right != N && left < right) {
		while (sum < S) {
			if (right < N - 1) {
				right++;
				res++;
				sum += v[right];
			}
			else {
				right++;
				break;
			}
		}
		if (sum >= S) {
			min_res = min(min_res, res);
		}
		sum -= v[left++];
		res--;
	}

	return min_res;
}

int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> N >> S;
	vector<int> v(N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum += v[i];
		// 원소가 S보다 크면 1을 출력
		if (v[i] >= S) {
			cout << 1;
			return 0;
		}
	}

	// 합을 만드는 것이 불가능하다면 0을 출력
	if (sum < S) {
		cout << 0;
		return 0;
	}

	// 출력
	cout << func(v);
	return 0;
}
