#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int getNum(int M, int N, int x, int y) {
    // x는 x번째, x+M번째 x+2M번째... 나타남
    // y는 y번째, y+N번째 y+2N번째...
    // N, M 최소 공배수에서 return -1;

    int len;

    int a = N, b = M;

    while (a != b) {
        if (a < b) { a += N; }
        else { b += M; }
    }
    len = a;

    int ad, bd;

    for (int i = 0; x + i * M <= len; i++) {
        a = (x + i * M) % N;
        if (a == 0)a = N;
        if (a == y) return (x + i * M);
    }
    
    return -1;
}

int main()
{
    int T, M, N, x, y;
    cin >> T;
    vector<int> res(T);
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> x >> y;
        res[i] = getNum(M, N, x, y);
    }
    for (int i = 0; i < T; i++) {
        cout << res[i] << "\n";
    }
}

