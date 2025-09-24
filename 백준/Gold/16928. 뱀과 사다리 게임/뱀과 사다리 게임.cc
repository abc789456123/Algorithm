#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int MAX = 2147483647;
vector<vector<int>> board(101, { MAX, -1});

int main() {
	int N, M;
	cin >> N >> M;

	int start, end;

	for (int i = 0; i < N+M; i++) {
		cin >> start >> end;
		board[start][1] = end;
	}

	int dice[] = { 1,2,3,4,5,6 };

	queue<int> q;
	q.push(1);
	board[1][0] = 0;
	int x, dx;
	while (board[100][0]==MAX) {
		x = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			dx = x + dice[i];
			if (dx <= 100 && board[x][0] + 1 <= board[dx][0]) {
				if (board[dx][1] == -1) {
					board[dx][0] = board[x][0] + 1;
					q.push(dx);
				}
				else{
					dx = board[dx][1];
					if (board[x][0] + 1 <= board[dx][0]) {
						board[dx][0] = board[x][0] + 1;
						q.push(dx);
					}
				}
			}
		}
	}

	cout << board[100][0];
}