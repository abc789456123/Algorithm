#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;

void back_tracking(vector<int>& num, vector<int>& res, int index, vector<bool> &save) {
	//다 채웠으면 출력
	if (index >= M) {
		for (int i = 0; i < M; ++i) {
			cout << res[i] << (i + 1 == M ? '\n' : ' ');
		}
		return;
	}
	else {
		//index번째 숫자 입력
		//num에서 사용되지 않은 숫자를 사전순으로 사용
		//만약 중복된 res가 나온다면 나중에 main에서 삭제
		for (int i = 0; i < N; i++) {
			if (!save[i]) continue;
			if (i > 0 && num[i] == num[i - 1] && save[i - 1]) continue;
			res[index] = num[i];
			save[i] = false;
			back_tracking(num, res, index + 1, save);
			save[i] = true;
		}
	}

}

int main() {
	//빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	vector<int> num(N);
	vector<int> res(M);
	vector<bool> save(N, true);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	back_tracking(num, res, 0, save);
}