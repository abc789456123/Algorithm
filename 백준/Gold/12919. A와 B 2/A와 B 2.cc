#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int MAX_INT = 2147483647;
int N, M;

// 문자열의 뒤에 A를 추가한다.
// 문자열의 뒤에 B를 추가하고 문자열을 뒤집는다.
// 이 두 연산의 역을 수행하는 함수를 만듬

// 문자열 뒤에 A를 제거한다
void funcA(string &s) {
	if (*(s.end() - 1) == 'A') s.erase(s.end() - 1, s.end());
	//else cout << "불가능한 명령 A";
}

// 문자열을 뒤집고 뒤에 B를 제거한다
void funcB(string& s) {
	reverse(s.begin(), s.end());
	if (*(s.end() - 1) == 'B') s.pop_back();
	//else cout << "불가능한 명령 B";
}

string S, T;

// 문자열 앞에 B && 문자열 뒤에 A면 두개 모두 진행해서 분기
// 문자열 뒤에 A면 funcA 진행
// 문자열 앞에 B면 funcB 진행

bool func(string t) {
	if (t.size() == S.size()) {
		if (t.compare(S) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	// 문자열 앞에 B && 문자열 뒤에 A면 두개 모두 진행해서 분기
	if (*(t.begin()) == 'B' && *(t.end() - 1) == 'A') {
		string ta = t;
		string tb = t;
		funcA(ta);
		funcB(tb);
		return func(ta) || func(tb);
	}
	// 문자열 뒤에 A면 funcA 진행
	// 문자열 앞에 B면 funcB 진행
	else if (*(t.end() - 1) == 'A') {
		funcA(t);
		return func(t);
	}
	else if (*(t.begin()) == 'B') {
		funcB(t);
		return func(t);
	}
	return false;
}

int main() {
	//빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S;
	cin >> T;

	bool res = func(T);
	cout << (res ? "1" : "0");
}
