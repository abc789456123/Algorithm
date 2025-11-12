#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int N = 1;
// index위치의 숫자를 만들 수 있는지 체크하는 함수
bool func(vector<int>& v, int index) {
	int left = 0, right = v.size() - 1, target = v[index];
	if (left == index) {
		left++;
	}
	if (right == index) {
		right--;
	}
	while (left < right) {
		int now = v[left] + v[right];
		if (now == target) {
			return true;
		}
		else if(now < target) {
			left++;
			if (index == left) {
				left++;
			}
		}
		else if(now > target) {
			right--;
			if (index == right) {
				right--;
			}
		}
	}
	return false;
}

int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	int res = 0;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (func(v, i)) res++;
	}

	// 출력
	cout << res;
}
