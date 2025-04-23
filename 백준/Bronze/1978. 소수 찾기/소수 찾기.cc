#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, a;
	vector <int> num;
	int cnt = 0;
	int res = 0;

	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> a;
		num.push_back(a);
	}

	for (int i = 0; i < N;i++) {
		a = num[i];
		if (a != 1) {
			for (int j = 1;j < (a / 2 + 1);j++) {
				if (a % j == 0) {
					cnt++;
				}
			}
		}
		if (cnt == 1) {
			res++;
		}
		cnt = 0;
	}
	cout << res;
}
