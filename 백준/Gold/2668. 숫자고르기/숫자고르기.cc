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

vector<int> get_numlist(vector<int> const& v) {
	// v값 받아서
	vector<int> numlist = v;
	sort(numlist.begin(), numlist.end());
	//101 삭제
	numlist.erase(unique(numlist.begin(), numlist.end()) - 1, numlist.end());

	return numlist;
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N;
	vector<int> v(N + 1, 101);
	vector<bool> save(N + 1, true);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	

	// 로직

	/*
	두번째 줄에 존재하는 숫자들의 목록을 따로 목록화함
	해당 목록의 첫 숫자번째 칸부터 v를 순회
	예시)
	1 2 3 4 5 6 7
	3 1 1 5 5 4 6
	-> 2번째 줄에 1, 3, 4, 5, 6만 있기 때문에 나머지 칸 삭제
	1 3 4 5 6
	3 1 5 5 4
	-> 2번째 줄에 1, 3, 4, 5만 있기 때문에 나머지 칸 삭제
	1 3 4 5
	3 1 5 5
	-> 2번째 줄에 1, 3, 5만 있기 때문에 나머지 칸 삭제
	1 3 5
	3 1 5
	-> 2번째 줄에 1, 3, 5만 있는데 더 지울 칸이 없으므로 이대로 리턴
	*/
	
	bool flag = false;	// 칸을 지웠는지 체크
	while (!flag) {
		flag = true;
		vector<int> numlist;
		numlist = get_numlist(v);
		for (int i = 1; i <= N; i++) {
			if (v[i] != 101) {
				auto it = find(numlist.begin(), numlist.end(), i);
				// 지워야 하는 칸이면 지움
				if (it == numlist.end()) {
					flag = false;
					v[i] = 101;
				}
			}
		}
	}

	// 출력
	vector<int> numlist;
	numlist = get_numlist(v);
	cout << numlist.size() << "\n";
	for (int i : numlist) {
		cout << i << "\n";
	}

	return 0;
}
