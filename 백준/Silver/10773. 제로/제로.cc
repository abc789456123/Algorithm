#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main()
{
	stack <int> stk;

	int N;
	cin >> N;
	int num;
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) {
			stk.pop();
		}
		else {
			stk.push(num);
		}
	}

	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	cout << res << "\n";
	return 0;
}
