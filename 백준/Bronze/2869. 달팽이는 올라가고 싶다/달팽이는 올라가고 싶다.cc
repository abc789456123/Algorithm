#include <iostream>
#include <vector>

using namespace std;
/*
v-a
v+b
v-a
*/


int main()
{
	int a, b, v;
	cin >> a >> b >> v;
	int day = 0;
	day = (v - a) / (a - b);
	if ((v-a)%(a-b) != 0) day++;
	cout << day+1;
}
