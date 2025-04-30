#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	//입력 받기 
	int N, M;
	cin >> N >> M;
	string str;

	map<int, string> dex1;
	map<string, int> dex2;
	vector<string> res;

	for (int i = 0;i < N;i++) {
		cin >> str;
		dex1[i + 1] = str;
		dex2[str] = i + 1;
	}

	for (int i = 0;i < M;i++) {
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9') {
			res.push_back(dex1[stoi(str)]);
		}
		else {
			res.push_back(to_string(dex2[str]));
		}
	}

	for (int i = 0;i < res.size();i++) {
		cout << res.at(i) << "\n";
	}


	return 0;


}
