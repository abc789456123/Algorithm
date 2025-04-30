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

	//입력 받기 
	int N=0;
	cin >> N;
	vector<int> NUMS(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> NUMS.at(i);
	}

	//기능 구현
	stack<int> stk;
	vector<char> res;
	stk.push(1);
	res.push_back('+');
	int point = 0;
	int num = 2;
	bool flag = true;

	if (N == 1) {
		cout << '+' << endl;
		cout << '-' << endl;
		return 0;
	}

	while (point!=N) {
		if (num-1 > N) {
			flag = false;
			break;
		}

		if (!stk.empty() && stk.top() == NUMS.at(point)) {
			stk.pop();
			res.push_back('-');
			point++;
		}
		else {
			stk.push(num++);
			res.push_back('+');
		}
	}
	if (flag == true) {
		for (int i = 0;i < res.size();i++) {
			cout << res.at(i) << "\n";
		}
	}
	else {
		cout << "NO";
	}

	return 0;


}
