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

int test() {
	int num;
	string str1, str2;
	cin >> num;
	vector<string> save;
	map<string, int> m;
	for (int i = 0;i < num;i++) {
		cin >> str1 >> str2;
		auto it = find(save.begin(), save.end(), str1);
		if (it == save.end()) {
			m[str2]++;
			save.push_back(str1);
		}
	}
	int res = 1;
	for (auto it = m.begin(); it != m.end(); it++) {
		res *= (it->second + 1);
	}
	return res - 1;
}

int main()
{

	//입력 받기 
	int N;
	cin >> N;

	vector<int> res;
	for (int i = 0;i < N;i++) {
		res.push_back(test());
	}
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << "\n";
	}

	return 0;
}

