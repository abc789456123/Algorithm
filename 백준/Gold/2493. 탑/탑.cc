#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <stack>

using namespace std;

int N;

// index 위치의 타워가 보내는 신호를 누가 받을지 return하는 함수
// 당연하게도 시간초과 나서 실패, 반례 경우도 있었음
// 문제 알고리즘탭 확인하고 스택 사용해야하는거 확인하고 다시 풀었음
int func(vector<int> towers, int index) {
	int tower = towers[index];
	for (int i = index - 1; i >= 0; i--) {
		if (towers[i] > tower) return i + 1;
	}
	return 0;
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N;

	vector<int> towers(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> towers[i];
	}
	//로직

	vector<int> res(N, 0);
	// 인덱스와 높이 저장
	stack<pair<int,int>> s;
	pair<int, int> p;
	int i1, i2;

	for (int i = N - 1; i >= 0; i--) {
		// 오른쪽 타워부터 스택에 넣음
		if (s.empty()) {
			s.push({ towers[i], i });
		}
		else {
			while (!s.empty()) {
				p = s.top();
				i1 = p.first;
				i2 = p.second;
				if (towers[i] >= i1) {
					if (res[i2] == 0) {
						res[i2] = i + 1;
					}
					s.pop();
				}
				else {
					break;
				}
			}
			s.push({ towers[i], i });
		}
	}


	// 출력
	for (int i = 0; i < N; i++) {
		cout << res[i];
		if (i != N - 1)cout << " ";
	}

	return 0;
}
