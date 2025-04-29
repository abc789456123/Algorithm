#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>

using namespace std;

int findMax(int* arr, int size) {
	int maxv = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > maxv) {
			maxv = arr[i];
		}
	}
	return maxv;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int doc, target;
	int point = 0;

	int** arr = new int*[N];
	int* res = new int[N]();
	int a;
	int flag = 0;
	int max = 0;

	//N개의 테스트 케이스 수행
	for (int i = 0;i < N;i++) {
		cin >> doc >> target;
		arr[i] = new int[doc]();

		//doc개의 문서 입력
		for(int j=0;j<doc;j++){
			cin >> a;
			arr[i][j] = a;
		}

		//타겟 문서가 인쇄될 때까지 문서 인쇄 진행
		while (arr[i][target] != 0) {
			//문서 인쇄
			if (arr[i][point] == findMax(arr[i], doc)) {
				arr[i][point] = 0;
				point++;
				res[i]++;
			}
			//인쇄 불가, 다음 문서 탐색
			else {
				point++;
			}

			if (point == doc) {
				point = 0;
			}
		}

		point = 0;
		flag = 0;
	}

	for (int i = 0;i < N;i++) {
		cout << res[i] << "\n";
	}

	//할당 해제
	for (int i = 0;i < N;i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] res;
	return 0;
}
