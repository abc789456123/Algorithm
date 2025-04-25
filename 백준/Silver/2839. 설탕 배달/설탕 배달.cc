#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int res = 0;

	int a;
	while (N != 0) {

		if (N % 5 == 0) {
			res += N / 5;
			break;
		}
		N -= 3;
		res++;
		if (N < 0) {
			res = -1;
			break;
		}

		
	}
	cout << res;
}
