#include <iostream>
#include <string>
#include <vector>

using namespace std;

string call_str(int num, string str) {
	int len = str.size();
	string res;

	for (int i = 0; i < len; i++) {
		for (int j = 0;j < num;j++) {
			res += str.at(i);
		}
	}
	return res;
}

int main()
{
	int a, b;
	string str1, str2;
	vector <string> result;
	cin >> a;
	for (int i = 0; i < a;i++) {
		cin >> b >> str1;
		str2 = call_str(b, str1);
		result.push_back(str2);
	}

	for (int i = 0; i < a;i++) {
		cout << result.at(i) << endl;
	}
}
