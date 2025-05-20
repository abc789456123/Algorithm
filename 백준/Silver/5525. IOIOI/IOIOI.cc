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
	int res = 0;

	for (int i = 1; i < (M - 1); i++) {
		if (S[i-1] == 'I'&& S[i] == 'O'&& S[i+1] == 'I') {
			cnt++;
			i++;
			if (cnt >= N) {
				res++;
			}
		}
		else {
			cnt = 0;
		}
		
	}

	cout << res;

	return 0;
}
