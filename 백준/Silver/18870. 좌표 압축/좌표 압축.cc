#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

int zip(const vector<int>& v, const vector<int>& sort_v, int index) {
	int target = v[index];
	int res = lower_bound(sort_v.begin(), sort_v.end(), target) - sort_v.begin();

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0;i < N;i++) {
		cin >> v[i];
	}

	vector<int> sort_v = v;
	sort(sort_v.begin(), sort_v.end());

	sort_v.erase(unique(sort_v.begin(), sort_v.end()), sort_v.end());

	for (int i = 0;i < N;i++) {
		cout << zip(v, sort_v, i) << " ";
	}

	return 0;
}


