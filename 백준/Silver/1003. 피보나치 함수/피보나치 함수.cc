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

vector<int> cnt01(int N) {
	queue<int> qn;
	int *arr = new int[N+1]();
	int index = N;
	if (N == 0) {
		return { 1, 0 };
	}
	else if (N == 1) {
		arr[1]++;
	}
	else {
		arr[N]++;
	}
	
	int n1, n2;
	for (index;index >= 2;index--) {

		while (arr[index] != 0) {
			arr[index - 1]++;
			arr[index - 2]++;
			arr[index]--;
		}
			
	}

	return { arr[0], arr[1]};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력 받기 
	int N;
	cin >> N;

	vector<vector<int>> res;
	int num;
	for (int i = 0;i < N;i++) {
		cin >> num;
		res.push_back(cnt01(num));
	}
	for (int i = 0;i < res.size();i++) {
		cout << res[i][0] << " " << res[i][1] << "\n";
	}

	return 0;
}
