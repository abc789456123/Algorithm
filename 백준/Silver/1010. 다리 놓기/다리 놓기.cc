#include <iostream>
#include <vector>
using namespace std;

void set_arr(vector<vector<int>>& arr) {
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 30; j++) {
            if (i == j) {
                arr[i][j] = 1;
            }
            else if (i == 1) {
                arr[i][j] = j;
            }
            else {
                for (int k = 0; k <= (j - i);k++) {
                    arr[i][j] += arr[i - 1][j - 1 - k];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력 받기
    int T;
    cin >> T;

    vector<vector<int>> arr(31, vector<int>(31, 0));
    set_arr(arr);

    vector<int> res(T);
    int N, M;

    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        res[i] = arr[N][M];
    }

    for (int i = 0; i < T; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}
