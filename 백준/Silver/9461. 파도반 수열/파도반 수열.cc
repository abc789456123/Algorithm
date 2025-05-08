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
	cin >> N;
	
	long long arr[105];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int i = 6;i <= 101;i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	vector<long long> res;

	for (int i = 0; i < N; i++) {
		cin >> M;
		res.push_back(arr[M]);
	}

	for (int i = 0;i < res.size();i++) {
		cout << res.at(i) << "\n";
	}

	return 0;
}


/*
1, 1, 1, 2, 2, 3, 4, 5, 
       7, 9, 12 ,16, 21​
	   28 37

*/