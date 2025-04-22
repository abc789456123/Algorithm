#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num, num1;
	vector <int> vec;
	cin >> num;
	for (int i = 0; i < num;i++) {
		cin >> num1;
		vec.push_back(num1);
	}
	int max, min;
	max = *max_element(vec.begin(), vec.end());
	min = *min_element(vec.begin(), vec.end());

	cout << min << " " << max;
}
