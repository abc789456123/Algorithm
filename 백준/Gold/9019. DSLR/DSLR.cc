#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>

using namespace std;
// D, S, L, R 계산
int cal_D(int i) {
	int res = 2 * i;
	if (res > 9999) res %= 10000;
	return res;
}
int cal_S(int i) {
	int res = i - 1;
	if (i == 0)res = 9999;
	return res;
}
int cal_L(int i) {
	string res;
	if (i < 10) res = "000" + to_string(i);
	else if (i < 100) res = "00" + to_string(i);
	else if (i < 1000) res = "0" + to_string(i);
	else if (i < 10000) res = to_string(i);

	char c = res[0];
	res[0] = res[1];
	res[1] = res[2];
	res[2] = res[3];
	res[3] = c;
	return stoi(res);
}
int cal_R(int i) {
	string res;
	if (i < 10) res = "000" + to_string(i);
	else if (i < 100) res = "00" + to_string(i);
	else if (i < 1000) res = "0" + to_string(i);
	else if (i < 10000) res = to_string(i);

	char c = res[0];
	res[0] = res[3];
	res[3] = res[2];
	res[2] = res[1];
	res[1] = c;
	return stoi(res);
}

// BFS
string BFS(int A, int B) {
	vector<pair<bool, string>> v(10000, {true, ""});
	v[A].first = false;
	queue<int> q;
	q.push(A);
	int top;
	int cal_top[4];
	while (!q.empty()) {
		top = q.front();
		q.pop();

		cal_top[0] = cal_D(top);
		cal_top[1] = cal_S(top);
		cal_top[2] = cal_L(top);
		cal_top[3] = cal_R(top);
		
		for (int i = 0; i < 4; i++) {
			if (v[cal_top[i]].first == true) {
				v[cal_top[i]].first = false;
				q.push(cal_top[i]);
				if (i == 0) {
					v[cal_top[i]].second = v[top].second + "D";
				}
				else if (i == 1) {
					v[cal_top[i]].second = v[top].second + "S";
				}
				else if (i == 2) {
					v[cal_top[i]].second = v[top].second + "L";
				}
				else if (i == 3) {
					v[cal_top[i]].second = v[top].second + "R";
				}
				if (cal_top[i] == B)return v[cal_top[i]].second;
			}
		}
	}

	return v[B].second;
}

int main()
{
	int T;
	cin >> T;
	vector<string> res(T);
	int a, b;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		res[i] = BFS(a, b);
	}

	for (string str : res) {
		cout << str << "\n";
	}
}

