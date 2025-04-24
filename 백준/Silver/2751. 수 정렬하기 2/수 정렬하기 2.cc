#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <iostream>

using namespace std;

void merge(int* v, int* tempArr, int left, int right) {

	//temp에 원본 복사
	for (int i = left; i <= right;i++) {
		tempArr[i] = v[i];
	}

	//temp 반으로 가르기
	int tempLeft = left;
	int mid = (left + right) / 2;
	int tempRight = mid + 1;
	int writeIndex = left;

	//반으로 나눠진거 비교하면서 원본에 덮어쓰기
	//한쪽 배열이 다 소진되면 반복문 종료
	while (tempLeft <= mid && tempRight <= right) {
		if (tempArr[tempLeft] <= tempArr[tempRight]) {
			v[writeIndex++] = tempArr[tempLeft++];
		}
		else {
			v[writeIndex++] = tempArr[tempRight++];
		}
	}
	int remain = 0;
	//나머지 한쪽 배열에 소진되지 않은 요소 원본에 덮어쓰기
	while (tempLeft <= mid) {
		v[writeIndex++] = tempArr[tempLeft++];
	}
	while (tempRight <= right) {
		v[writeIndex++] = tempArr[tempRight++];
	}

}

void partition(int* v, int* tempArr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		partition(v, tempArr, left, mid);
		partition(v, tempArr, mid + 1, right);
		merge(v, tempArr, left, right);
	}
}

int main()
{
	int NUM;
	cin >> NUM;

	int* v = new int[NUM];
	int* tempArr = new int[NUM];

	for (int i = 0;i < NUM;i++) {
		cin >> v[i];
	}
	partition(v, tempArr, 0, NUM - 1);

	for (int i = 0; i < NUM;i++) {
		cout << v[i] << "\n";
	}

	delete[] v;
	delete[] tempArr;

}

