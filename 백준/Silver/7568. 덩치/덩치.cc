#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//상대가 나보다 더 덩치가 큰 경우 3번에 +1점
void comp(vector<int> &v1, vector<int> &v2) {
	if (v1[1] > v2[1] && v1[2] > v2[2]) {
		v2[3]++;
	}
	else if (v1[1] < v2[1] && v1[2] < v2[2]) {
		v1[3]++;
	}
}

// 순서, 무게, 키, 덩치 순서로 벡터 저장
int main()
{
	int N;
	cin >> N;
	vector<vector<int>> people;
	vector<int> v(4,0);
	for (int i = 0;i < N;i++) {
		v[0] = i;
		cin >> v[1] >> v[2];
		people.push_back(v);
	}
	//덩치 비교
	for (int i = 0;i < N - 1;i++) {
		for (int j = i + 1;j < N;j++) {
			comp(people[i], people[j]);
		}
	}
	vector<int> v4; //덩치 벡터 추출
	for (int i = 0;i < N;i++) {
		v4.push_back(people[i][3]);
	}
	sort(v4.begin(), v4.end());

	int rate = 1;
	for (int i = 0;i < N;i++) {
		people[i][0] = people[i][3] + 1;
	}

	for (int i = 0;i < N;i++) {
		cout << people[i][0] <<" ";
	}
}

