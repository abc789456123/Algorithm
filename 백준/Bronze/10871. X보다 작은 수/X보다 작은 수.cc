#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a, b, c;
	vector<int> res;
	cin >> a >> b;
	for (int i = 0;i < a;i++) {
		cin >> c;
		if (c < b) {
			res.push_back(c);
		}
	}
	for (int j = 0; j < res.size();j++) {
		cout << res.at(j) << " ";
	}
}
