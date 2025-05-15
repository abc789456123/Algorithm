#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
	string str;
	string s = "";
	cin >> str;
	int res = 0;
	bool flag = true;
	for (int i = 0;i < str.size();i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			s += str[i];
		}
		else if (str[i] == '-' && flag == true) {
			flag = false;
			res += stoi(s);
			s = "";
		}
		else {
			if (flag == true) {
				res += stoi(s);
				s = "";
			}
			else {
				res -= stoi(s);
				s = "";
			}
		}
	}
	if (flag == true) {
		res += stoi(s);
	}
	else {
		res -= stoi(s);
	}
	cout << res;
}

