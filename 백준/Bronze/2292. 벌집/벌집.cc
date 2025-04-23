#include <iostream>

using namespace std;

//1 (6) 7 (12) 19 (18) 37 (24) 61

int main()
{
	int N;
	int cal = 1;
	int cnt = 1;
	int i = 1;
	cin >> N;
	while (N > cal) {
		cal = cal + (6 * i);
		i++;
		cnt++;
	}
	cout << cnt;
}
