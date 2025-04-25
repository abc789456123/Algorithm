#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//비교 기준 함수
bool comp(const vector<int> &v1, const vector<int> &v2) {
	if (v1[0] == v2[0]) {
		return v1[1] < v2[1];
	}
	else {
		return v1[0] < v2[0];
	}
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> v;
	vector<int> vin(2, 0);

	for (int i = 0;i < N;i++) {
		cin >> vin[0] >> vin[1];
		v.push_back(vin);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0;i < N;i++) {
		cout << v[i][0] << " " << v[i][1] << "\n";
	}

}

