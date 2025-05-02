#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력 받기 
	int N;
	cin >> N;

	int* arr = new int[N + 1]();
	arr[N] = 0;
	arr[0] = -1; //접근 불가 위치

	queue<int> q;
	q.push(N);
	int index = N;

	while (!q.empty()) {
		index = q.front();
		if (index % 3 == 0 && arr[index/3] == 0) {
			arr[index / 3] = arr[index] + 1;
			q.push(index / 3);
		}
		if (index % 2 == 0 && arr[index / 2] == 0) {
			arr[index / 2] = arr[index] + 1;
			q.push(index / 2);
		}
		if (arr[index - 1] == 0) {
			arr[index - 1] = arr[index] + 1;
			q.push(index - 1);
		}
		q.pop();
	}

	cout << arr[1];

	return 0;
}
