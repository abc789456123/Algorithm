#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>

using namespace std;

void sosu(int * arr, int N) {
	for (int i = 0;i < N+1;i++) {
		arr[i] = i;
	}
	for (int i = 2;i < N + 1;i++) {
		if (arr[i] > 0) {
			for (int j = 2*i;j < N +1;j += i) {
				arr[j] = -1;
			}
		}
	}
	arr[1] = -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;
	int* arr = new int[N + 1];
	sosu(arr, N);

	for (int i = M;i <= N;i++) {
		if (arr[i] > 0) {
			cout << arr[i] << "\n";
		}
	}

	return 0;
}
