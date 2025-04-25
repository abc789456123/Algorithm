#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 8*8 = 64 보드에 색칠한다면 
// n개를 칠하거나 64-n개를 칠하면 정상적으로 만들 수 있음
int check(vector<string> chess) {
	int cnt = 0;
	for (int i = 0;i < 8;i++) {
		if (i > 0 && chess[i][0] == chess[i - 1][0]) {
			if (chess[i][0] == 'B') {
				chess[i][0] = 'W';
				cnt++;
			}
			else {
				chess[i][0] = 'B';
				cnt++;
			}
		}
		for (int j = 0; j < 7;j++) {
			if (chess[i][j] == chess[i][j + 1]) {
				if (chess[i][j + 1] == 'B') {
					chess[i][j + 1] = 'W';
					cnt++;
				}
				else {
					chess[i][j + 1] = 'B';
					cnt++;
				}
			}
		}
	}
	return cnt < (64 - cnt) ? cnt : (64 - cnt);
}

int main()
{
	//보드를 한칸씩 옮겨가며 8*8 size로 만들고 그걸 검사

	int x, y;				//사이즈
	vector<string> all;		//전체 보드
	vector<string> test(8);	//8*8사이즈 테스트 보드
	cin >> x >> y;

	string str;

	for (int i = 0; i < x;i++) {
		cin >> str;
		all.push_back(str);
	}

	int min_sco = 64;

	// 전체 보드를 88사이즈로 자르기
	for (int i = 0;i < x - 7;i++) {
		for (int j = 0;j < y - 7;j++) {
			for (int k = 0;k < 8;k++) {
				str = all[i+k].substr(j, 8);	//i+k,j위치의 str 8개를 가져오기
				test[k] = str;
			}
			min_sco = min(min_sco, check(test));
		}
	}

	cout << min_sco;

}

