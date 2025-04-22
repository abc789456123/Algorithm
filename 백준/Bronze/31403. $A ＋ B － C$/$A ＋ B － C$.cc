#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;
	cout << (a + b - c) << endl;
	
	string strA, strB;
	strA = to_string(a);
	strB = to_string(b);

	strA += strB;
	a = stoi(strA);
	cout << (a - c);
}
