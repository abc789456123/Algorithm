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

long long num(int n) {
	int res;
	int* fib = new int[n + 1];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2;i < n + 1;i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력 받기 
	int N;
	cin >> N;

	cout << num(N);

	return 0;
}
