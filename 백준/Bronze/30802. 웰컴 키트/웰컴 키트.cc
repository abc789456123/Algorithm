#include <iostream>
#include <vector>

using namespace std;

void Pen(int N, int P) {
	cout << N / P << " " << N % P;
}
void TTT(int T, vector<int> size) {
	int len = size.size();
	int res = 0;
	for (int i = 0; i < len;i++) {
		if (size[i] != 0) {
			res++;
			res += size[i] / T;
			if (size[i] % T == 0) {
				res--;
			}
		}
	}
	cout << res;
}

int main()
{
	int N;
	int T, P;
	int S, M, L, XL, XXL, XXXL;
	vector<int> size;

	cin >> N;
	cin >> S >> M >> L >> XL >> XXL >> XXXL;
	cin >> T >> P;

	size.push_back(S);
	size.push_back(M);
	size.push_back(L);
	size.push_back(XL);
	size.push_back(XXL);
	size.push_back(XXXL);

	TTT(T, size);
	cout << endl;
	Pen(N, P);
}
