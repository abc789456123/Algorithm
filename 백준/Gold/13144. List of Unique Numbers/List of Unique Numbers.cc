#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

int N, S, R, C;

// 시간초과로 실패한 함수
// v의 모든 인덱스를 한번씩 거치면서 어디까지 이동 가능한지 체크
int func(const vector<int>&v, int index) {
	int size = -1;
	set<int> set;
	while (size != set.size() && index < N) {
		size = set.size();
		set.insert(v[index++]);
	}
	size = set.size();
	return size;
}

// 두포인터 적용한 함수
long long func2(const vector<int>& v) {
	int left = 0, right = 0;
	long long res = 0;
	set<int> set;
	while (left < N) {
		// 중복된 수가 나올 때 까지 right를 밀기
		while (right < N && set.find(v[right]) == set.end()) {
			set.insert(v[right]);
			right++;
		}
		// 경우의 수 더하기
		res += right - left;
		// left 한칸 밀기
		set.erase(v[left++]);
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
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}


	// 출력
	cout << func2(v);
	return 0;
}
