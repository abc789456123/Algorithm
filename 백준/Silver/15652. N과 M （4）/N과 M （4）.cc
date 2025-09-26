#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int arr[9]{};

void back_tracking(int index, int min) {
	if (index == M+1) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = min; i <= N; i++) {
			arr[index] = i;
			back_tracking(index + 1, i);
		}
	}
}


int main() {
	cin >> N >> M;
	back_tracking(1, 1);
}