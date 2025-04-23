#include <iostream>
#include <vector>

using namespace std;

double max(vector<double> v) {
	int len = v.size();
	double maxV = 0;
	for (int i = 0; i < len;i++) {
		if (v.at(i) > maxV) {
			maxV = v.at(i);
		}
	}
	return maxV;
}

int main()
{
	int N;
	double a;
	cin >> N;
	vector<double> v;
	for (int i = 0;i < N;i++) {
		cin >> a;
		v.push_back(a);
	}

	double maxV = max(v);
	double res = 0;
	for (int i = 0; i < v.size();i++) {
		res += (v.at(i) / maxV) * 100;
	}
	cout << res / v.size();
}
