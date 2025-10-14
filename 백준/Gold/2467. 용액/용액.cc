#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits> // INT_MAX 사용

using namespace std;

int N = 0, M = 0;

bool comp_AB(long long A, long long B) {
	if (A < 0) A = A * -1;
	if (B < 0) B = B * -1;
	if (A < B) return true;
	else return false;
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N;
	vector<long long> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	vector<long long> res = { LLONG_MAX, LLONG_MAX , LLONG_MAX };
	int start = 0, end = N - 1;
	// 로직
	// start 위치의 값과 end 위치의 값을 더함
	// 더한 값을 res[0]과 비교하여 절댓값이 더 작으면 해당 요소들로 교체
	// 만약 더한값이 양수면 end를 -1하고, 음수면 start를 +1하여 계속 진행
	// 0이 나온다면 해당 값을 리턴
	long long tmp;
	while (start < end) {
		tmp = v[start] + v[end];
		if (tmp == 0) {
			res[1] = v[start];
			res[2] = v[end];
			break;
		}
		else if (tmp > 0) {
			// tmp가 더 절댓값이 작은 경우
			if (comp_AB(tmp, res[0])) {
				res[0] = tmp;
				res[1] = v[start];
				res[2] = v[end];
			}
			end--;
		}
		else if (tmp < 0) {
			// tmp가 더 절댓값이 작은 경우
			if (comp_AB(tmp, res[0])) {
				res[0] = tmp;
				res[1] = v[start];
				res[2] = v[end];
			}
			start++;
		}
	}

	// 출력
	cout << res[1] << " " << res[2];

	return 0;
}
