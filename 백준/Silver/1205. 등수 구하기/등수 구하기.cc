#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
점수랑 같은 사람이 있으면 랭크 메김, 같은 등수 더 있는지 몇명 있는지 확인
점수랑 같은 사람이 없으면 큰수 바로 아래 등수 메김
*/


int main() {
	int N, score, P;
	cin >> N >> score >> P;
	vector<int> ranking;
	int num = 0;
	int rank = 1;
	int listNum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		ranking.push_back(num);
	}

	auto it = find(ranking.begin(), ranking.end(), score);

	//점수가 같은 사람이 있다면
	if (it != ranking.end()) {
		rank = it - ranking.begin() + 1;
		for (int i = rank-1; i < N; i++) {
			if (ranking[i] == score) {
				listNum = i + 2;
			}
		}
	}
	//점수가 같은 사람이 없다면
	else {
		for (int i = 0; i < N; i++) {
			if (ranking[i] > score) {
				rank = i + 2;
				listNum = i + 2;
			}
		}
	}

	if (listNum > P) cout << "-1";
	else cout << rank;

}