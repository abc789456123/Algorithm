#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int len;
	int a, b;
	vector <int> v;


	cin >> len;

	for (int i = 0; i < len; i++) {
		cin >> a >> b;
		v.push_back(a + b);
	}
	for (int i = 0; i < len; i++) {
		cout << v.at(i) << endl;
	}
}
