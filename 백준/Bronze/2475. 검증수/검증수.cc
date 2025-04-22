#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int j = 0;
    int a;
    int b = 0;
    vector<int> v;
    while (j < 5) {
        cin >> a;
        v.push_back(a);
        j++;
    }
    for (int i = 0; i < v.size();i++) {
        b += pow(v[i],2);
    }
    cout << b % 10;
}
