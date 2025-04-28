#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string comm;
	cin >> N;
	int a;
	vector<int> v;
	vector <int> res;

	for (int i = 0;i < N;i++) {

		cin >> comm;
		if (comm == "push") {
			cin >> a;
			v.push_back(a);
		}
		else if (comm == "top") {
			if (!v.empty()) {
				res.push_back(v.at(v.size() - 1));
			}
			else {
				res.push_back(-1);
			}
		}
		else if (comm == "pop") {
			if (!v.empty()) {
				res.push_back(v.at(v.size() - 1));
				v.erase(v.end() - 1);
			}
			else {
				res.push_back(-1);
			}
		}
		else if (comm == "size") {
			res.push_back(v.size());
		}
		else if (comm == "empty") {
			if (!v.empty()) {
				res.push_back(0);
			}
			else {
				res.push_back(1);
			}
		}
	}
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << "\n";
	}

	return 0;
}
