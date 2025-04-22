#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a;
	vector<int> v1, res;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		v1.push_back(a);
	}
	for (int i = 0;i < v1.size();i++) {
		res.push_back((v1.at(i) % 42));
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	cout << res.size();
}
