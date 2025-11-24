#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, S, R, C;
string s, bomb, str;
int bomb_len;

bool check(string& str) {
	int len = str.size();
	if (len < bomb_len) {
		return false;
	}
	for (int i = bomb_len; i > 0; i--) {
		if (str[len - i] != bomb[bomb_len - i]) {
			return false;
		}
	}
	return true;
}


int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> s;
	cin >> bomb;

	bomb_len = bomb.size();
	char key = bomb[bomb_len - 1];

	for (int i = 0; i < s.size(); i++) {
		str.push_back(s[i]);
		if (s[i] == key) {
			if (check(str)) {
				for (int j = 0; j < bomb_len; j++) {
					str.pop_back();
				}
			}
		}
	}


	// 출력
	if (!str.empty()) {
		cout << str;
	}
	else {
		cout << "FRULA";
	}
	return 0;
}
