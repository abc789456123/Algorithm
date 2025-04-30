#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string command;
	int num;
	int set[20];
	fill(set, set + 20, 0);
	vector<bool> res;

	//입력 받기 
	int M=0;
	cin >> M;

	for (int i = 0;i < M;i++) {
		cin >> command;
		if (command == "add") {
			cin >> num;
			if (set[num-1] != 0) {
				// num이 set에 있는 경우
				continue;
			}
			else {
				set[num - 1] = num;
			}
		}
		else if (command == "remove") {
			cin >> num;
			if (set[num - 1] != 0) {
				// num이 set에 있는 경우
				set[num - 1] = 0;
			}
			else {
				continue;
			}
		}
		else if (command == "check") {
			cin >> num;
			if (set[num - 1] != 0) {
				// num이 set에 있는 경우
				res.push_back(1);
			}
			else {
				res.push_back(0);
			}
		}
		else if (command == "toggle") {
			cin >> num;
			if (set[num - 1] != 0) {
				// num이 set에 있는 경우
				set[num - 1] = 0;
			}
			else {
				set[num - 1] = num;
			}
		}
		else if (command == "all") {
			for (int i = 0;i < 20;i++) {
				set[i] = i + 1;
			}
		}
		else if (command == "empty") {
			for (int i = 0;i < 20;i++) {
				set[i] = 0;
			}
		}
	}

	for (int i = 0;i < res.size();i++) {
		cout << res[i] << "\n";
	}
	return 0;


}
