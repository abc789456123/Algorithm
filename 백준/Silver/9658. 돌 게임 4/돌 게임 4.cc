#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	//상근이가 이기면 true
	//창영이가 이기면 false
	vector<bool> v(1001, true);

	//상근 선턴
	
	v[0] = 0;
	v[1] = false;
	v[2] = true;
	v[3] = false;
	v[4] = true;
	v[5] = true;

	for (int i = 6; i <= N;i++) {
		if (v[i - 1] == true && v[i - 3] == true && v[i - 4] == true) {
			v[i] = false;
		}
		else {
			v[i] = true;
		}
	}

	if (v[N] == true) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}
}

