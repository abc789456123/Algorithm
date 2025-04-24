#include <iostream>
#include <string>

using namespace std;

int main()
{
	string strArr[3];
	for (int i = 0; i < 3;i++) {
		cin >> strArr[i];
	}
	string key;
	int n;
	for (int i = 0; i < 3;i++) {
		if (strArr[i] != "Fizz" && strArr[i] != "Buzz" && strArr[i] != "FizzBuzz") {
			key = strArr[i];
			n = i;
			break;
		}
	}

	int keyInt = stoi(key) + (3 - n);

	if (keyInt % 3 == 0 && keyInt % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (keyInt % 3 == 0 && keyInt % 5 != 0) {
		cout << "Fizz";
	}
	else if (keyInt % 3 != 0 && keyInt % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << keyInt;
	}
}
