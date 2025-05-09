#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력 받기
    int T;
    cin >> T;

    vector<int> v(T);
    v[0] = 1;
    v[1] = 2;

    for (int i = 2;i < T;i++) {
        v[i] = (v[i - 1] + v[i - 2])%10007;
    }
    cout << v[T - 1];
    return 0;
}

/*
1   1
2   2
3   3
4   5
5   

*/