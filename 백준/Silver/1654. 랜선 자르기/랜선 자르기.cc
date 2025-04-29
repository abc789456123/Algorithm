#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>

using namespace std;

// check 함수는 랜선 길이 len으로 만들 수 있는 랜선 수를 계산
long long check(const vector<long long>& v, long long len, int K, int N) {
    long long res = 0;
    for (int i = 0; i < K; i++) {
        res += v[i] / len;
        if (res >= N) return res;  // 필요한 만큼 만들었으면 조기 종료
    }
    return res;
}

// 이진 탐색 함수
long long binary_search(const vector<long long>& v, long long left, long long right, int K, int N) {
    long long result = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid == 0) break;  // mid == 0이 되면 나누기 에러 방지

        if (check(v, mid, K, N) >= N) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    cin >> K >> N;

    vector<long long> v(K);
    for (int i = 0; i < K; i++) {
        cin >> v[i];
    }

    long long right = *max_element(v.begin(), v.end());
    long long answer = binary_search(v, 1, right, K, N);

    cout << answer;

    return 0;
}
