#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits> // INT_MAX 사용

using namespace std;

int N, M;
int num;


// 각 테스트 케이스에 대해 ASCII 순서에 따라 결과가 0이 되는 모든 수식을 출력한다. 
// 각 테스트 케이스의 결과는 한 줄을 띄워 구분한다.
// 맨 마지막 요소에 ""을 넣는다
// 마지막 숫자를 바로 연산하지 않고 뒤 연산부호가 ' '가 아닐 경우에 연산을 확정함
// 현재 넣을 숫자, 직전의 문자, 현재 식의 문자열, 현재 식의 합, 직전 부호
char oper[3] = { ' ', '+', '-' };
void func(int now, int last, string exp, int sum, char op) {
	if (now > num) {	// 부호 다 채운 경우
		int final;
		if (op == '+') {
			final = sum + last;
		}
		else if (op == '-') {
			final = sum - last;
		}
		if (final == 0) {
			cout << exp << "\n";
		}
		return;
	}
	const string snow = to_string(now);	// 붙이기 결과 숫자 출력
	for (char c : oper) {
		if (c == ' ') {
			string s1 = exp + ' ' + snow;
			int sign = (last >= 0) ? 1 : -1;
			int newLast = sign * (abs(last) * 10 + now);

			func(now + 1, newLast, s1, sum, op);
		}
		else if (c == '+') {
			// 직전 계산 확정
			string s2;
			int newSum = 0;
			if (op == '+') {
				newSum = sum + last;
			}
			else if (op == '-') {
				newSum = sum - last;
			}
			s2 = exp + '+' + to_string(now);
			func(now + 1, now, s2, newSum, '+');

		}
		else if (c == '-') {
			// 직전 계산 확정
			string s3;
			int newSum = 0;
			if (op == '+') {
				newSum = sum + last;
			}
			else if (op == '-') {
				newSum = sum - last;
			}
			s3 = exp + '-' + to_string(now);
			func(now + 1, now, s3, newSum, '-');
		}
	}
}

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		func(2, 1, "1", 0, '+');
		if (i != N - 1) cout << "\n";
	}

	// 출력

	return 0;
}
