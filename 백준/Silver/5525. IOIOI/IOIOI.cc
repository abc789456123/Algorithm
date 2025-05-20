#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

string makeP(int N) {
	string res = "I";
	for (int i = 0;i < N;i++) {
		res += "OI";
	}
	return res;
}

void searchio(string S, string str, int index) {

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;

	string str = makeP(N);
	int strLen = str.size();

	int cnt = 0;
	bool flag = true;

	for (int i = 0; i < (M - strLen + 1); i++) {
		for (int j = 0;j < strLen;j++) {
			if (S[i + j] != str[j]) {
				flag = false;
				break;
			}
		}
		if (flag == true) cnt++;
		else flag = true;
	}

	cout << cnt;

	return 0;
}
