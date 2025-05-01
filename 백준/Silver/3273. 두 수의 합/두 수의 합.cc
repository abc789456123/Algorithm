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
	int* arr = new int[N];

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	int X;
	cin >> X;
	int res = 0;

	sort(arr, arr + N);
	int left = 0;
	int right = N - 1;

	while (left < right) {
		if (arr[left] + arr[right] == X) {
			res++;
			left++;
		}
		else if (arr[left] + arr[right] < X) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << res;

	return 0;
}
