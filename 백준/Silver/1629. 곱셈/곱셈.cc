#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long A, B, C;
long long num = 1;

long long devide(long long b) {
	if (b == 0) return 1;
	if (b == 1) return A % C;

	num = devide(b / 2) % C;
	if (b % 2 == 0) return (num * num) % C;
	return (num * num) % C * A % C;
}

int main() {
	//빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	long long res = devide(B);

	cout << res;
}