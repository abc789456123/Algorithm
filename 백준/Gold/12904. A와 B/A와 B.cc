#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int MAX_INT = 2147483647;
int N, M;

// 문자열의 뒤에 A를 추가한다.
// 문자열을 뒤집고 뒤에 B를 추가한다.
// 이 두 연산의 역을 수행하는 함수를 만듬

// 문자열 뒤에 A를 제거한다
void funcA(string &s) {
	if (*(s.end() - 1) == 'A') s.erase(s.end() - 1, s.end());
	else cout << "불가능한 명령 A";
}

// 문자열 뒤에 B를 제거하고 뒤집는다
void funcB(string& s) {
	if (*(s.end() - 1) == 'B') s.erase(s.end() - 1, s.end());
	else cout << "불가능한 명령 B";
	reverse(s.begin(), s.end());
}

string S, T;
int len;

// 문자열 뒤에 A면 funcA 진행
// 문자열 뒤에 B면 funcB 진행

int func(string &t) {
	if (t.size() == S.size()) {
		if (t.compare(S) == 0) {
			cout << "1";
			return 0;
		}
		else {
			cout << "0";
			return 0;
		}
	}
	if (*(t.end() - 1) == 'A') funcA(t);
	else if (*(t.end() - 1) == 'B') funcB(t);
	func(t);
	return 0;
}

int main() {
	//빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S;
	cin >> T;

	func(T);
}
