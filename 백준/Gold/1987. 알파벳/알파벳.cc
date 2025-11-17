#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, S, R, C;
int max_res = 0;

/*
세로R칸, 가로C칸으로 된 표 모양의 보드가 있다. 
보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 
좌측 상단 칸 (1행1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 
새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 
즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 
말이 지나는 칸은 좌측 상단의 칸도 포함된다.
*/

// a,b를 넣고 다음 이동 방향 탐색
void func(const vector<string>& v, vector<bool>& alphabet,
	int a, int b, int res) {
	max_res = max(max_res, res);

	// 상하좌우 이동방향 탐색
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	for (int i = 0; i < 4; i++) {
		int x = a + dx[i];
		int y = b + dy[i];
		// 범위체크
		if (x < 0 || x >= R || y < 0 || y >= C)continue;
		char c = v[x][y];
		int index = c - 'A';
		// 이동 가능한 칸인 경우
		if (alphabet[index]) {
			alphabet[index] = false;
			func(v, alphabet, x, y, res + 1);
			alphabet[index] = true;
		}
	}
	return;
}

int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> R >> C;
	vector<string> v(R);
	vector<bool> alphabet(26, true);
	string str;
	for (int i = 0; i < R; i++) {
		cin >> v[i];
	}
	// 0,0 넣기
	int n = v[0][0] - 'A';
	alphabet[n] = false;

	func(v, alphabet, 0, 0, 1);

	// 출력
	cout << max_res;
	return 0;
}
