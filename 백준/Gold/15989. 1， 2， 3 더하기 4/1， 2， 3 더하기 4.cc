#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;

// 순서가 다른 것도 다른 것으로 치는 경우의 함수
int func1(int n) {
	int num[10001]{};
	int res = 0;
	int index = 0;
	int dx[3] = { 1,2,3 };
	queue<int> q;
	int fq;
	q.push(0);
	while (!q.empty()) {
		fq = q.front();
		q.pop();
		for (int i : dx) {
			if (fq + i > n) continue;
			num[fq + i]++;
			q.push(fq + i);
		}
	}
	return num[n];
}


// 순서가 같은 것도 같은 것으로 치는 경우의 함수
int func2(int n) {
	int num[10001]{};
	int res = 0;
	int index = 0;
	int max = 3;
	//첫째값은 현재값, 둘째값은 더할수있는 최소값
	pair<int, int> p;
	queue<pair<int,int>> q;

	q.push({ 0,1 });
	while (!q.empty()) {
		p = q.front();
		q.pop();
		index = p.first;
		for (int i = p.second; i <= max; i++) {
			if (index + i > n)continue;
			num[index + i]++;
			q.push({ index + i, i });
		}
	}
	
	return num[n];
}

// 알고리즘 확인하고 DP로 풀어본 함수
vector<vector<int>> func3(int n) {
	vector<vector<int>> v(10001, vector<int>(4, 0));
	v[1][1] = 1; // 1
	v[2][1] = 1; // 11
	v[2][2] = 1; // 2
	v[3][1] = 1; // 111
	v[3][2] = 1; // 12
	v[3][3] = 1; // 3
	v[4][1] = 1; // 1111
	v[4][2] = 2; // 112, 22
	v[4][3] = 1; // 13
	v[5][1] = 1;
	v[5][2] = 2; // 1112, 122 
	v[5][3] = 2; // 113, 23

	//v[x][1] = 무조건 1
	//v[x][2] = v[x-2][1] + v[x-2][2]
	//v[x][3] = v[x-3][1] + v[x-3][2] + v[x-3][3]

	for (int x = 6; x <= n; x++) {
		v[x][1] = 1;
		v[x][2] = v[x - 2][1] + v[x - 2][2];
		v[x][3] = v[x - 3][1] + v[x - 3][2] + v[x - 3][3];
	}

	return v;
}

int main() {
	//빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int* in = new int[N];
	int out = 0;

	for (int i = 0; i < N; i++) {
		cin >> in[i];
	}
	int maxnum = *max_element(in, in + N);
	vector<vector<int>> res = func3(maxnum);
	int num;
	for (int i = 0; i < N; i++) {
		num = in[i];
		for (int i = 1; i < 4; i++) {
			out += res[num][i];
		}
		cout << out << "\n";
		out = 0;
	}

	delete[] in;
}