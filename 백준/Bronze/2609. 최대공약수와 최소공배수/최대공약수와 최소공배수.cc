#include <iostream>
#include <vector>

using namespace std;

void calA(int a, int b) {	//최대 공약수 계산
	for (int i = b; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i;
			break;
		}
	}
}

void calB(int a, int b) {
	for (int i = a;;i++) {
		if (i % a == 0 && i % b == 0) {
			cout << i;
			break;
		}
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	if (a >= b) {//a가 더 크게 설정
		calA(a, b);
		cout << endl;
		calB(a, b);
	}
	else {
		calA(b, a);
		cout << endl;
		calB(b, a);
	}
}
