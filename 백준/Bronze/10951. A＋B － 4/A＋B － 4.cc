#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int input;
	vector<int> num;

	while (cin >> input) {
		num.push_back(input);
	}
	for (int i = 0; i < num.size();i += 2) {
		cout << num[i] + num[i + 1] << endl;
	}
}
