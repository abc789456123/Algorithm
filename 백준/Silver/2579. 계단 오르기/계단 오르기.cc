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

	int* arr = new int[N+1]();
	int* save = new int[N+1]();
	int res = 0;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		res += arr[i];
	}

	int index = 0;

	if (N <= 2) {
		cout << res;
		return 0;
	}

	for (int i = 1;i < 4; i++) {
		save[i] = arr[i];
	}

	for (int i = 4; i < N; i++) {
		save[i] = min(save[i - 2], save[i - 3]) + arr[i];
	}

	cout << res - min(save[N - 1], save[N - 2]);

	delete[] arr;
	return 0;
}
