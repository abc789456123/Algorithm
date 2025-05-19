#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	pair <int, int> p;
	vector<pair<int, int>> v;
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) 
		{ if (a.second == b.second) { return a.first < b.first; }
		return a.second < b.second; });

	int res = 0;
	int now = 0;
	for (pair <int, int> vp : v) {
		if (vp.first >= now) {
			res++;
			now = vp.second;
		}
	}

	cout << res;
	
	return 0;
}


