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
	int N, M;
	cin >> N >> M;

	int* arr = new int[N];
	int* res = new int[M]();

	cin >> arr[0];

	for (int i = 1;i < N;i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int a, b;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		if(a>1){
			res[i] = arr[b - 1] - arr[a - 2];
		}
		else {
			res[i] = arr[b - 1];
		}
	}

	for (int i = 0;i < M;i++) {
		cout << res[i] << "\n";
	}
	
	delete[] arr;
	delete[] res;

	return 0;
}

