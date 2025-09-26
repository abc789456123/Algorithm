#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> arr(8, -1);
vector<int> num;

void back_tracking(int index) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < num.size(); i++) {
			auto it = find(arr.begin(), arr.end(), num[i]);
			if (it == arr.end()) {
				arr[index] = num[i];
				back_tracking(index + 1);
				//이미 사용된걸 초기화해주는 것!!
				arr[index] = -1;
			}
		}
	}
}


int main() {
	cin >> N >> M;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		num.push_back(a);
	}
	sort(num.begin(), num.end());
	back_tracking(0);
}