#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int MAX_INT = 2147483647;
int N = 0, K = 0;

// 벨트를 한칸씩 회전시킨다. N번칸에 있던 로봇은 벨트에 내려 사라진다.
// 1번칸에 가까이 있는 로봇부터 앞으로 한칸 이동할 수 있다면 이동, 불가능하다면 정지
// 한칸 이동한다면 도착한 칸의 내구도는 -1이 된다
// 1번칸에 내구도가 양수면 로봇을 올린다.
// 벨트에 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다

int main() {
	//빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int res = 0;
	int cnt = 0;

	cin >> N >> K;

	vector<int> belt(2 * N + 1, 0);
	//로봇이 없으면 true 있으면 false
	vector<bool> robot(2 * N + 1, true);

	for (int i = 1; i < belt.size(); i++) {
		cin >> belt[i];
	}

	while (cnt < K) {
		res++;
		// 벨트를 한칸씩 회전시킨다. N번칸에 있던 로봇은 벨트에 내려 사라진다.
		int num = belt[1];
		bool tf = robot[1];		//이동시킬 값 저장변수
		bool tmp;				//스왑용변수
		for (int i = 1; i < belt.size(); i++) {
			if (i == belt.size() - 1) {
				swap(num, belt[1]);
				tmp = robot[1];
				robot[1] = tf;
				tf = tmp;
			}
			else {
				swap(num, belt[i + 1]);
				tmp = robot[i + 1];
				robot[i + 1] = tf;
				tf = tmp;
			}
		}

		//내리는 위치의(N번칸에 있는) 로봇 하차
		robot[N] = true;

		// 가장 먼저 벨트에 올라간 로봇부터 앞으로 한칸 이동할 수 있다면 이동, 불가능하다면 정지
		// 한칸 이동한다면 도착한 칸의 내구도는 -1이 된다

		for (int i = N - 1; i > 0; i--) {
			if (!robot[i] && robot[i + 1] && belt[i + 1] > 0) {
				robot[i] = true;
				robot[i + 1] = false;
				belt[i + 1]--;
			}
		}

		//내리는 위치의(N번칸에 있는) 로봇 만약 있을 수 있으니 하차
		robot[N] = true;

		// 올리는칸(1번)에 내구도가 양수면 로봇을 올린다.
		if (belt[1] > 0 && robot[1]) {
			robot[1] = false;
			belt[1]--;
		}

		// 벨트에 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다
		// 그렇지 않다면 1번으로 돌아간다
		// 종료되었을 때 몇 번째 단계가 진행 중이었는지 반환

		cnt = 0;
		for (int i = 1; i < robot.size(); i++) {
			if (belt[i] == 0) {
				cnt++;
			}
		}
	}

	cout << res;
}
