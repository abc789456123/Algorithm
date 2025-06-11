#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v(N + 1);
	v[0] = 1;

	for (int i = 2; i < N + 1; i+=2) {
		v[i] = 3 * v[i - 2];
		for (int j = 4; j <= i; j += 2) {
			v[i] += 2 * v[i - j];
		}
	}
	cout << v[N];
}

