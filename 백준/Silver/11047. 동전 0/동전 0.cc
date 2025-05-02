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
	int N, K;
	cin >> N >> K;
	int* arr = new int[N];

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	int res = 0;

	for (int i = N - 1;i >= 0;i--) {
		while (arr[i] <= K) {
			K -= arr[i];
			res++;
		}
		if (K == 0) break;
	}

	cout << res;


	return 0;
}
