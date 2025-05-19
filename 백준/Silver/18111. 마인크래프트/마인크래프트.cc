#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

//모든 높이를 H로 만드는데 몇초 걸리는지 계산하는 함수
//불가능하면 -1리턴
int timer(const vector<vector<int>>& v, int B, int H) {
	int cnt = 0;
	for (int i = 0;i < v.size();i++) {
		for (int j = 0;j < v[i].size();j++) {
			if (v[i][j] > H) { //블럭 캐기
				cnt += 2 * (v[i][j] - H);
				B += v[i][j] - H;
			}
			else if (v[i][j] < H) { //블럭 설치
				cnt += H - v[i][j];
				B -= H - v[i][j];
			}
		}
	}

	if (B < 0) 	return -1;
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> v((N), vector<int>(M));

	int min_b = 256;
	int max_b = 0;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> v[i][j];
			if (v[i][j] < min_b)	min_b = v[i][j];
			if (v[i][j] > max_b)	max_b = v[i][j];
		}
	}

	int res[2];
	int r;
	
	res[0] = timer(v, B, min_b);
	res[1] = min_b;

	for (int i = min_b + 1;i <= max_b;i++) {
		r = timer(v, B, i);
		if (r > -1 && res[0] >= r) {
			res[0] = r;	//시간
			res[1] = i;	//높이
		}
	}

	cout << res[0] << " " << res[1];

	return 0;
}

/*
	블럭 한칸 제거에는 2초가 소모
	블럭 한칸 설치에는 1초와 B 1개가 소모

	걸리는 시간과 땅의 높이를 출력하시오. 
	답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것
*/