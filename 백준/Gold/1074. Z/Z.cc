#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int Z(int N, int r, int c) {
	int len = static_cast<int>(pow(2, N));
	int a = 0;
	int b = 0;

	int p1[] = { a,  b };
	int p2[] = { a, len / 2 + b };
	int p3[] = { len / 2 + a, b };
	int p4[] = { len /2 + a, len /2 + b };
	int blocksize;
	int a1, a2, a3, a4;
	a1 = 0;

	while (N > 0) {
		len = static_cast<int>(pow(2, N));
		blocksize = pow(4, N - 1);
		p1[0] = a;
		p1[1] = b;

		p2[0] = a;
		p2[1] = len / 2 + b;

		p3[0] = len / 2 + a;
		p3[1] = b;

		p4[0] = len / 2 + a;
		p4[1] = len / 2 + b;

		a2 = a1 + blocksize;
		a3 = a2 + blocksize;
		a4 = a3 + blocksize;

		if (p1[0] == r && p1[1] == c) {
			return a1;
		}
		if (p2[0] == r && p2[1] == c) {
			return a2;
		}
		if (p3[0] == r && p3[1] == c) {
			return a3;
		}
		if (p4[0] == r && p4[1] == c) {
			return a4;
		}

		if (r < p3[0]) {
			if (c < p2[1]) { //좌상단 타겟 존재
				N--;
				continue;
			}
			else {			//우상단 타겟 존재
				a1 = a2;
				a = p2[0];
				b = p2[1];
			}
		}
		else {
			if (c < p2[1]) { //좌하단 타겟 존재
				a1 = a3;
				a = p3[0];
				b = p3[1];
			}
			else {			//우하단 타겟 존재
				a1 = a4;
				a = p4[0];
				b = p4[1];
			}
		}
		N--;
	}
	return -1;
}

int main()
{
	int N, r, c;
	cin >> N >> r >> c;

	int len = static_cast<int>(pow(2, N));

	cout << Z(N, r, c);
}

