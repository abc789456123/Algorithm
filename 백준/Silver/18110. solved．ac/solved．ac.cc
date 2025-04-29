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
	
	int N;
	cin >> N;

	if (N == 0) {
		cout << 0;
		return 0;
	}

	int* arr = new int[N];

	int a;
	double res = 0;

	int cut = round(N * 0.15);

	for (int i = 0; i < N;i++) {
		cin >> a;
		arr[i] = a;
	}

	sort(arr, arr+N);

	for (int i = 0; i < cut;i++) {
		arr[i] = 0;
		arr[N - 1 - i] = 0;
	}
	for (int i = 0; i < N;i++) {
		res += arr[i];
	}


	res = round(res / (N-cut-cut));

	cout << res;

	delete[] arr;

	return 0;
}
