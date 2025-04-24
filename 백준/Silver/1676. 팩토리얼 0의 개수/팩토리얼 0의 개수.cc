#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	int res = 0;
	int two = 0;
	int five = 0;
	int num;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		num = i;
		while (num % 2 == 0) {
			two++;
			num /= 2;
		}

		while (num % 5 == 0) {
			five++;
			num /= 5;
		}

		while (two > 0 && five > 0) {
			two--;
			five--;
			res++;
		}
	}
	cout << res;
}
