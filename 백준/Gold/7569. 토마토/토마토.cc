#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>

using namespace std;


int main()
{
	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> v(M, vector<vector<int>>(N,
		vector<int>(H)));
	queue<vector<int>> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> v[k][j][i];
				if (v[k][j][i] == 1) {
					q.push({ k,j,i });
				}
			}
		}
	}

	int res = 1;
	int dx[6] = { 1, -1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, 1, -1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1 };
	vector<int> top;
	int x, y, z;
	while (!q.empty()) {
		top = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			x = top[0] + dx[i];
			y = top[1] + dy[i];
			z = top[2] + dz[i];
			if (x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H
				&& v[x][y][z] == 0) {
				v[x][y][z] = v[top[0]][top[1]][top[2]] + 1;
				if (v[x][y][z] > res) res = v[x][y][z];
				q.push({ x,y,z });
			}
		}
	}
	
	bool check = true;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (v[k][j][i] == 0) {
					check = false;
					break;
				}
			}
		}
	}
	if (check == true)	cout << res - 1;
	else cout << "-1" ;
}

