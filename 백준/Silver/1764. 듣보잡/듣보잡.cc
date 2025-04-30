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

	set<string> s;
	string str;
	for (int i = 0;i < N;i++) {
		cin >> str;
		s.insert(str);
	}
	int ssize = s.size();
	vector<string> res;
	for (int i = 0;i < M;i++) {
		cin >> str;
		s.insert(str);
		if (ssize == s.size()) {
			res.push_back(str);
		}
		else {
			ssize = s.size();
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i = 0;i < res.size();i++) {
		cout << res.at(i) << "\n";
	}

	return 0;
}
