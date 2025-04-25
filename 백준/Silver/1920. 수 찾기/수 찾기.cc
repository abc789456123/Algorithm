#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find(int* v, int left, int right, int num) {	//벡터, 비교위치, 찾는수

	if (left > right) return 0;
	int mid = (left + right) / 2;
	if (v[mid] == num) return 1;
	else if (v[mid] < num) {
		return find(v, mid+1, right, num);
	}
	else {
		return find(v, left, mid-1, num);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int num;
	cin >> N;
	int* vn = new int[N];

	for (int i = 0;i < N;i++) {
		cin >> num;
		vn[i]=num;
	}

	sort(vn, vn+N);

	int M;
	cin >> M;
	int* vm = new int[M];

	for (int i = 0;i < M;i++) {
		cin >> num;
		vm[i] = num;
	}

	for (int i = 0;i < M;i++) {
		cout << find(vn, 0, N-1, vm[i]) << "\n";
	}
}

