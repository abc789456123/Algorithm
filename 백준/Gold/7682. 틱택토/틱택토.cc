#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits> // INT_MAX 사용

using namespace std;

int N = 0, M = 0;
// 만약에 빙고가 여러개일 때 하나의 수로 두개 이상의 빙고를 만든건지 체크
bool check_cross(vector<vector<pair<int, int>>> cross) {
	vector<pair<int, int>> v1 = cross[0];
	pair<int, int>p;
	bool flag = false;
	for (int i = 1; i < cross.size(); i++) {
		if (!flag) {
			for (int j = 0; j < 3; j++) {
				p = v1[j];
				auto it = find(cross[i].begin(), cross[i].end(), p);
				if (it != cross[i].end()) {
					flag = true;
					break;
				}
			}
			if (!flag) return false;
		}
		else {
			auto it = find(cross[i].begin(), cross[i].end(), p);
			if (it == cross[i].end()) {
				return false;
			}
		}
	}
	return true;
}
// 게임이 끝난 상태면 valid
// valid 할 수 있는 3가지 경우
// X가 이긴 경우
// X가 O보다 1개 많다. O로 이루어진 빙고가 없다. X 빙고가 하나 있다
// O가 이긴 경우
// O과 X 개수가 같다. O로 이루어진 빙고가 하나 있다. X 빙고가 없다
// 무승부
// X가 5개, O이 4개 존재. 각각 빙고가 없다
// 이외의 모든 상황은 invalid임
string func(string s) {
	vector<vector<char>> v(3, vector<char>(3));
	int index = 0, Ocnt = 0, Xcnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			v[i][j] = s[index++];
			if (v[i][j] == 'O') {
				Ocnt++;
			}
			else if (v[i][j] == 'X') {
				Xcnt++;
			}
		}
	}
	vector<vector<pair<int, int>>> check = { {{0,0},{0,1},{0,2}}, {{1,0},{1,1},{1,2}} ,
	{{2,0},{2,1},{2,2}} ,{{0,0},{1,0},{2,0}} ,{{0,1},{1,1},{2,1}} ,{{0,2},{1,2},{2,2}},
	{{0,0},{1,1},{2,2}} ,{{0,2},{1,1},{2,0}} };
	vector<vector<pair<int, int>>> cross;
	pair<int, int>p;
	int xbingo = 0, obingo = 0, x, y, xnt = 0, ont = 0;
	// X가 이긴 경우
	if (Xcnt == Ocnt + 1) {
		// X의 빙고만 단 하나 존재함을 찾는 로직
		for (int i = 0; i < 8; i++) {
			xnt = ont = 0;
			for (int j = 0; j < 3; j++) {
				p = check[i][j];
				x = p.first;
				y = p.second;
				if (v[x][y] == 'O') {
					ont++;
				}
				else if (v[x][y] == 'X') {
					xnt++;
				}
				else {
					break;
				}
			}
			if (ont == 3) {
				obingo++;
				ont = 0;
				xnt = 0;
			}
			else if (xnt == 3) {
				cross.push_back(check[i]);
				xbingo++;
				ont = 0;
				xnt = 0;
			}
			else {
				ont = 0;
				xnt = 0;
			}
		}
		if (xbingo == 1 && obingo == 0) {
			return "valid";
		}
		else if (xbingo>1 && check_cross(cross) && obingo == 0) {
			return "valid";
		}
	}
	// O가 이긴 경우
	else if (Xcnt == Ocnt) {
		// O의 빙고만 단 하나 존재함을 찾는 로직
		for (int i = 0; i < 8; i++) {
			xnt = ont = 0;
			for (int j = 0; j < 3; j++) {
				p = check[i][j];
				x = p.first;
				y = p.second;
				if (v[x][y] == 'O') {
					ont++;
				}
				else if (v[x][y] == 'X') {
					xnt++;
				}
				else {
					break;
				}
			}
			if (ont == 3) {
				cross.push_back(check[i]);
				obingo++;
				ont = 0;
				xnt = 0;
			}
			else if (xnt == 3) {
				xbingo++;
				ont = 0;
				xnt = 0;
			}
			else {
				ont = 0;
				xnt = 0;
			}
		}
		if (obingo == 1 && xbingo == 0) {
			return "valid";
		}
		else if (obingo > 1 && check_cross(cross) && xbingo == 0) {
			return "valid";
		}
	}
	// 무승부
	if (Xcnt == 5 && Ocnt == 4) {
		xbingo = 0;
		obingo = 0;
		// 유효한 빙고가 단 하나도 없음을 찾는 로직
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 3; j++) {
				p = check[i][j];
				x = p.first;
				y = p.second;
				if (v[x][y] == 'O') {
					ont++;
				}
				else if (v[x][y] == 'X') {
					xnt++;
				}
				else {
					break;
				}
			}
			if (ont == 3) {
				obingo++;
				ont = 0;
				xnt = 0;
			}
			else if (xnt == 3) {
				xbingo++;
				ont = 0;
				xnt = 0;
			}
			else {
				ont = 0;
				xnt = 0;
			}
		}
		if (obingo == 0 && xbingo == 0) {
			return "valid";
		}
	}
	return "invalid";
}


int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	string s = "";
	string res;
	vector<string> out;
	

	// 로직
	while (s != "end") {
		cin >> s;
		if (s != "end") {
			res = func(s);
			out.push_back(res);
		}
	}

	// 출력
	for (string str : out) {
		cout << str << "\n";
	}

	return 0;
}
