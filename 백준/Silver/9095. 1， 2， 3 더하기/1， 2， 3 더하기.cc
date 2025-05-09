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
	int T;
	cin >> T;
	vector<long long> res(11,0);

	res.at(1) = 1;
	res.at(2) = 2;
	res.at(3) = 4;
	res.at(4) = 7;

	for (int i = 5; i <= 10;i++) {
		res.at(i) = res.at(i - 1) + res.at(i - 2) + res.at(i - 3);
	}
	int* in = new int[T]();
	for (int i = 0;i < T;i++) {
		cin >> in[i];
	}

	for (int i = 0;i < T;i++) {
		cout << res.at(in[i]) << "\n";
	}

	return 0;
}

 
