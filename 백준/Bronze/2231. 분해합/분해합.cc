#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calcul(int num) {
	string str;
	str = to_string(num);
	int res = num;
	for (int i = 0;i < str.size();i++) {
		res += str[i] - '0';
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	int num;
	int res = 0;
	for(int i = N; i>0; i--){
		num = i;
		if (calcul(num) == N) {
			res = num;
			break;
		}
	}
	for (int i = 1; i < 101; i++) {
		if (calcul(num - i) == N) {
			res = num - i;
		}
	}
	cout << res;
}
