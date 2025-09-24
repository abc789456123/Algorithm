#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void male(vector<bool>& switchs, int index) {
	int num = index;
	while (num < switchs.size()) {
		switchs[num] = !switchs[num];
		num += index;
	}
}

void female(vector<bool>& switchs, int index) {
	switchs[index] = !switchs[index];
	int i = 1;
	while (true) {
		if (index - i > 0 && index + i < switchs.size() && switchs[index - i] == switchs[index + i]) {
			switchs[index - i] = !switchs[index - i];
			switchs[index + i] = !switchs[index + i];
			i++;
		}
		else {
			break;
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<bool> switchs (N + 1, 0);
	bool num;

	for (int i = 1; i <= N; i++) {
		cin >> num;
		switchs[i] = num;
	}

	int M;
	cin >> M;
	int x, y;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		switch (x) {
		case 1:
			male(switchs, y);
			break;
		case 2:
			female(switchs, y);
			break;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		cout << switchs[i] << " ";
		cnt++;
		if (cnt == 20) {
			cout << "\n";
			cnt = 0;
		}
	}
}