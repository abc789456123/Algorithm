#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int NUM;
	cin >> NUM;

	int* v = new int[10001]();
	int a;

	for (int i = 0;i < NUM;i++) {
		cin >> a;
		v[a]++;
	}

	for (int i = 0; i < 10001;i++) {
		while (v[i] > 0) {
			cout << i << "\n";
			v[i]--;
		}
	}

	delete [] v;

}
