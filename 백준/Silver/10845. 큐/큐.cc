#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

int MAX = 10000;
int* queue = new int[MAX]();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string comm;
	cin >> N;
	int a;
	int* res = new int[N]();
	int resindex = 0;
	int size = 0;

	for (int i = 0; i < N;i++) {
		cin >> comm;
		if (comm == "push") {
			cin >> a;
			queue[size] = a;
			size++;
		}
		else if (comm == "pop") {
			if (size > 0) {
				res[resindex++] = queue[0];
				for (int j = 0;j < size;j++) {
					queue[j] = queue[j + 1];
				}
				size--;
			}
			else {
				res[resindex++] = -1;
			}
		}
		else if (comm == "size") {
			res[resindex++] = size;
		}
		else if (comm == "empty") {
			if (size == 0) {
				res[resindex++] = 1;
			}
			else {
				res[resindex++] = 0;
			}
		}
		else if (comm == "front") {
			if (size == 0) {
				res[resindex++] = -1;
			}
			else {
				res[resindex++] = queue[0];
			}
		}
		else if (comm == "back") {
			if (size == 0) {
				res[resindex++] = -1;
			}
			else {
				res[resindex++] = queue[size-1];
			}
		}
	}

	for (int i = 0;i < resindex;i++) {
		cout << res[i] << "\n";
	}

	delete[] res;
	delete[] queue;

	return 0;
}
