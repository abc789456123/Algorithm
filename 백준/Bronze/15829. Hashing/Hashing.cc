#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int len;
	string str;

	cin >> len >> str;

	int res = 0;

	for (int i = 0; i < len; i++) {
		res += (str[i] - 'a' + 1) * (pow(31, i));
	}
	cout << res;
}
