#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;

// x에서 y로 가는 경로가 있는지 탐색하는 함수
int search(const vector<vector<int>>& v, int x, int y) {
    int N = v.size();

    vector<bool> save(N, true);
    int top;
    queue <int> q;
    q.push(x);
    while (!q.empty()) {
        top = q.front();
        q.pop();
        for (int i : v[top]) {
            if (save[i] == true) {
                q.push(i);
                save[i] = false;
                if (save[y] == false) return 1;
            }
        }
    }

    if (save[y] == false) return 1;
    else return 0;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> v(N);

    int a, x, y;

    // 방향 그래프 채우기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a;
            if (a == 1) {
                v[i].push_back(j);
            }
        }
    }

    vector<vector<int>> res(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = search(v, i, j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

}

