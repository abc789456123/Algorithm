#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> F(n + 1); // 크기가 n+1인 벡터 선언

    F[0] = 0;
    F[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        F[i] = (F[i-1] + F[i-2]) % 1234567;
    }
    
    return F[n];
}
