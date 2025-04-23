#include <iostream>
#include <vector>

using namespace std;

//1 (6) 7 (12) 19 (18) 37 (24) 61

int main()
{
	int len, M;
	vector<int> card;
	int cnt;
	cin >> len >> M;
	for (int i = 0;i < len;i++) {
		cin >> cnt;
		card.push_back(cnt);
	}
	vector<int> sum;

	int inum, jnum, knum;
	for (int i = 0;i < len-2;i++) {
		inum = card[i];
		for (int j = i+1;j < len-1;j++) {
			jnum = card[j];
			for (int k = j+1;k < len;k++) {
				knum = card[k];
				sum.push_back(inum + jnum + knum);
				
			}
		}
	}
	int max = 0;
	for (int i = 0; i < sum.size();i++) {
		if (sum[i] > max && sum[i] <= M) {
			max = sum[i];
		}
	}

	cout << max;
}
