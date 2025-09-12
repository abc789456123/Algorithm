#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
*/

int N, M;
int arr[9] = {};

void func(int index, int point) { //index개 만큼 골랐고 고를 수 있는 최소값이 point이라는 뜻
	// index = m일 경우, 수열이 완성된 경우
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	// index 위치의 arr의 숫자를 채우기
	for (int i = point; i <= N; i++) {
		arr[index] = i;
		func(index + 1, i + 1);
	}
}

int main() {
	cin >> N >> M;

	//최대값이 N이고 길이가 M인 수열
	//수열의 길이가 M
	func(0,1);
}