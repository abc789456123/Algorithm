#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string check(string str) {
	stack<char> stk;
	int len = str.size();
	for (int i = 0;i < len;i++) {
		if (str[i] == '(') {
			stk.push(str[i]);
		}
		else if (str[i] == ')') {
			if (!stk.empty()&&stk.top() == '(') {
				stk.pop();
			} 
			else {
				return "NO";
			}
		}
	}
	if (stk.empty()) {
		return "YES";
	}
	return "NO";
}

int main()
{
	vector<string> strv;
	string str;
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> str;
		strv.push_back(str);
	}

	int len = strv.size();
	for (int i = 0;i < len;i++) {
		cout << check(strv[i]) << "\n";
	}
	return 0;
}
