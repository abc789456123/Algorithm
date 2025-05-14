#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int num;
	cin >> N;
	vector<int> v(50001, 100);
	
	v[0] = 0;
	v[1] = 1;
	v[2] = 2;

	for (int i = 2; i <= N;i++) {
		for (int j = 0;j * j <= i;j++) {
			v[i] = min(v[i], (v[i - (j * j)] + 1));
		}
	}

	cout << v[N];
}

