#include <iostream>
#include <string>
#include <vector>

using namespace std;

void check(int& cnt, int n) {
	string str = to_string(n);
	int flag = 0;
	for (int i = 0; i < str.size()-2;i++) {
		if (str[i] == '6'&& str[i+1] == '6'&& str[i+2] == '6') flag=1;
	}
	if (flag == 1) cnt++;
}

int main()
{
	int N;
	int cnt = 0;
	int num = 665;
	cin >> N;
	while (cnt != N) {
		check(cnt, num);
		num++;
	}
	cout << num-1;
}
