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
		if (str[i] == '(' || str[i] == '[') {
			stk.push(str[i]);
		}
		else if (str[i] == ')') {
			if (!stk.empty()&&stk.top() == '(') {
				stk.pop();
			} 
			else {
				return "no";
			}
		}
		else if (str[i] == ']') {
			if (!stk.empty() && stk.top() == '[') {
				stk.pop();
			} 
			else {
				return "no";
			}
		}
	}
	if (stk.empty()) {
		return "yes";
	}
	return "no";
}

int main()
{
	vector<string> strv;
	string str;
	while (str != ".") {
		getline(cin, str);
		strv.push_back(str);
	}
	int len = strv.size();
	for (int i = 0;i < len - 1;i++) {
		cout << check(strv[i]) << "\n";
	}
	return 0;
}
