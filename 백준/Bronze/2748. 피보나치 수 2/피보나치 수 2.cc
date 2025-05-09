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
	int N;
	cin >> N;
	vector<long long> res(N+1,0);

	res.at(1) = 1;

	for (int i = 2; i <= N;i++) {
		res.at(i) = res.at(i - 1) + res.at(i - 2);
	}

	cout << res.at(N);

	return 0;
}

 
 
