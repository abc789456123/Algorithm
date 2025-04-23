#include <iostream>
#include <vector>

using namespace std;
/*
“a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지
사람들의 수의 합만큼 사람들을 데려와 살아야 한다”
아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.
*/


int main()
{
	int T;
	int a;
	cin >> T;
	vector<int> v1;
	for (int i = 0; i < 2 * T;i++) {
		cin >> a;
		v1.push_back(a);
	}
	vector<vector<int>> apart(15,vector<int>(14,1)) ;
	for (int i = 1; i < 14; i++) {
		apart[0][i] = apart[0][i - 1] + 1;
	}
	for (int i = 1;i < 15;i++) {
		for (int j = 1;j < 14;j++) {
			apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
		}
	}
	for (int i = 0; i < v1.size();i += 2) {
		cout << apart[v1[i]][v1[i + 1]-1] << endl;
	}

}
