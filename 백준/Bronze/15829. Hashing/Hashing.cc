#include <iostream>
#include <string>

using namespace std;

long long Mpow(int num, int exp) {
	int MOD = 1234567891;
	long long res = 1;
	if (exp > 1) {
		for (int i = 0; i < exp;i++) {
			res = (res * num) % MOD;
		}
	}
	else if (exp == 1) {
		return 31;
	}
	else {
		return 1;
	}
	return res;
}

int main()
{
	int len;
	string str;

	cin >> len >> str;

	int MOD = 1234567891;

	long long res = 0;

	for (int i = 0; i < len; i++) {
		res += (str[i] - 'a' + 1) * (Mpow(31, i))%MOD;
		res %= MOD;
	}
	cout << res;
}
