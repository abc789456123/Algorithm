#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<int, int> m;

	int N1, N2;
	int in1, in2;

	cin >> N1;
	for (int i = 0;i < N1;i++) {
		cin >> in1;
		m[in1]++;
	}
	cin >> N2;
	for (int i = 0; i < N2;i++) {
		cin >> in2;
		cout << m[in2] << " ";
	}

	return 0;
}
