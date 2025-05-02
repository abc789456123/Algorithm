#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력 받기 
	int N, M;
	cin >> N >> M;
	map<string, string> m;
	string str1, str2;

	for (int i = 0;i < N;i++) {
		cin >> str1 >> str2;
		m[str1] = str2;
	}

	vector<string> res;

	for (int i = 0;i < M;i++) {
		cin >> str1;
		res.push_back(m[str1]);
	}

	for (int i = 0;i < M;i++) {
		cout << res[i] << "\n";
	}



	return 0;
}
