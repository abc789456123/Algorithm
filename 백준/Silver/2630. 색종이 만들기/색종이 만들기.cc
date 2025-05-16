#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

void cut(const vector<vector<int>> &v, int a, int b, int len, int &white, int &blue) {
	int mid = len / 2;
	bool blue_flag = true;
	bool white_flag = true;

	//현재영역 균일한지 체크
	for (int i = a;i < a + len;i++) {
		for (int j = b;j < b + len;j++) {
			if (v[i][j] == 0) blue_flag = false;
			else if (v[i][j] == 1) white_flag = false;
		}
		if (blue_flag == false && white_flag == false) break;
	}

	if (white_flag == true) {
		white++;
		return;
	}
	else if (blue_flag == true) {
		blue++;
		return;
	}
	else {
		cut(v, a, b, mid, white, blue);
		cut(v, a, b+mid, mid, white, blue);
		cut(v, a+mid, b, mid, white, blue);
		cut(v, a+mid, b+mid, mid, white, blue);
	}
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> v(N, vector<int>(N, 0));

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> v[i][j];
		}
	}

	int white = 0, blue = 0;

	cut(v, 0, 0, N, white, blue);

	cout << white << "\n" << blue;
}

