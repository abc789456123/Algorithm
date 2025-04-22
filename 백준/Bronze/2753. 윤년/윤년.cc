#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int res = 0;

    cin >> a;
    if (a % 4 == 0 && a % 100 != 0) {
        res = 1;
    }
    else if (a % 400 == 0) {
        res = 1;
    }
    cout << res;
}
