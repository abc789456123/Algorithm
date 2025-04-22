#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	string s;
	for (int i = 0;i < 8;i++) {
		cin >> s;
		str += s;
	}
	if (str == "12345678") {
		cout << "ascending";
	}
	else if (str == "87654321") {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}
}
