#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

void out(int X, multiset<int>& s, int &size,
	vector<int> &res) {
	if (size != 0) {
		//정상 출력
		res.push_back(*s.begin());
		s.erase(s.begin());
		size--;
	}
	else {
		//0출력
		res.push_back(0);
	}
}
void in(int X, multiset<int> &s) {
	s.insert(X);
}

int main()
{
	int N, X;
	cin >> N;
	multiset<int> s;
	int index = 0;
	int size = 0;
	vector<int> res;
	for (int i = 0;i < N;i++) {
		cin >> X;
		if (X == 0) {
			out(X, s, size, res);
			index += 1;
		}
		else {
			in(X, s);
			size++;
			index = 0;
		}
	}

	for (int i = 0;i < res.size();i++) {
		cout << res[i] << "\n";
	}
}

