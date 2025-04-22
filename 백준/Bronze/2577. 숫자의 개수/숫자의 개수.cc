#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int A, B, C;
	int num;
	string strNum;
	vector<int> v(10, 0);
	cin >> A >> B >> C;
	num = A * B * C;
	strNum = to_string(num);

	int index;

	for (int i = 0;i < strNum.size();i++) {
		index = strNum[i] - '0';
		v[index]++;
	}

	for (int i = 0;i < v.size();i++) {
		cout << v[i] << endl;
	}
}
