#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void vSort(vector<int>& v) {
	int len = v.size();
	int j = 0;
	for (int i = 0; i < len-1; i++) {
		for (int j = 0;j < len - 1;j++) {
			if (v.at(j) > v.at(j + 1)) {
				swap(v.at(j), v.at(j + 1));
			}
		}
	}
}

int main()
{
	int a = 1;
	int b = 1;
	int c = 1;
	vector<vector<int>> v;
	vector<int> vNow;

	while (a != 0 && b != 0 && c != 0) {
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	int len = v.size()-1;
	int temp = 0;
	for (int i = 0;i < len;i++) {
		vNow = v.at(i);
		vSort(vNow);
		if (pow(vNow[0], 2) + pow(vNow[1], 2) == pow(vNow[2], 2)) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
}
