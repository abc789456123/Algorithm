#include <iostream>

using namespace std;

int main()
{
	int a, b;
	int ansA = 1;
	int ansB = 1;
	cin >> a >> b;

	for (int i = (a - b + 1); i <= a;i++) {
		ansA *= i;
	}
	for (int i = 1; i <= b;i++) {
		ansB *= i;
	}
	cout << ansA / ansB;
}
