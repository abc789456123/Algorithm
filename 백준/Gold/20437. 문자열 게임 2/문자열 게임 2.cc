#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int MAX_INT = 2147483647;
int N = 0, K = 0;
string str;

// 가장 짧은 문자열 길이 구하기
int get_short(char c, const string& s, int K) {
	if (K <= 0) return MAX_INT;
	if (K == 1) return 1;
	// s안에 c의 개수는 v개 있음
	// 문자를 정확히 K개 포함하는 가장 짧은 문자열의 길이 반환
	int res = MAX_INT;
	// s안에 c의 위치 인덱스 v개를 추출하여 배열로 저장
	vector<int> vec;
	for (int i = 0; i < s.size();i++) {
		if (s[i] == c) {
			vec.push_back(i);
		}
	}
	// 배열을 for문 돌려서 i+K-1위치의 값과 i위치의 값의 차이를 비교하여 가장 짧은 값 저장
	int len = vec.size();
	for (int i = 0; i < len - K + 1; i++) {
		if (vec[i + K - 1] - vec[i] < res) {
			res = vec[i + K - 1] - vec[i];
		}
	}
	// 이후 최종 결과 값에 +1하여 반환
	if (res == MAX_INT) return res;
	else return res + 1;
}

// 가장 긴 문자열 길이 구하기
int get_long(char c, const string& s, int K) {
	if (K <= 0) return 0;
	if (K == 1) return 1;
	// s안에 c의 개수는 v개 있음
	// 문자를 정확히 K개 포함하는 가장 긴 문자열의 길이 반환
	int res = 0;
	// s안에 c의 위치 인덱스 v개를 추출하여 배열로 저장
	vector<int> vec;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == c) {
			vec.push_back(i);
		}
	}
	// 배열을 for문 돌려서 i+K-1위치의 값과 i위치의 값의 차이를 비교하여 가장 긴 값 저장
	int len = vec.size();
	for (int i = 0; i < len - K + 1; i++) {
		if (vec[i + K - 1] - vec[i] > res) {
			res = vec[i + K - 1] - vec[i];
		}
	}
	// 이후 최종 결과 값에 +1하여 반환
	if (res == 0) return res;
	else return res + 1;
}

vector<int> func(int K, string s) {
	// 각 문자들의 개수 카운트
	// 문자 개수가 K개 이상인 문자들로 가장 짧은 길이와 가장 긴 길이 구하기
	int short_result = MAX_INT, long_result = 0;
	int v;
	char c;
	int short_tmp, long_tmp;

	map<char, int> m;
	for (char ch : s) {
		m[ch]++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
	{
		v = it->second;
		if (v >= K) {
			c = it->first;
			// 짧은 문자열 길이 구하기
			short_tmp = get_short(c, s, K);
			if (short_tmp < short_result)short_result = short_tmp;
			// 가장 긴 문자열 길이 구하기
			long_tmp = get_long(c, s, K);
			if (long_tmp > long_result)long_result = long_tmp;
		}
	}

	if (short_result == MAX_INT && long_result == 0) {
		return { -1 };
	}
	else {
		return { short_result , long_result };
	}
}

int main() {
	//빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// ==================================

	// 가장 짧은 연속 문자열의 길이를 구한다.
	// 가장 긴 연속 문자열의 길이를 구한다.
	// 만약 만족하는 연속 문자열이 없을 시 -1을 출력한다.

	cin >> N;
	vector<vector<int>> res(N);

	for (int i = 0; i < N; i++) {
		cin >> str >> K;

		res[i] = func(K, str);
	}

	// 결과 출력
	for (int i = 0; i < N; i++) {
		if (res[i].size() == 1) {
			cout << res[i][0];  // -1인 경우
		}
		else {
			cout << res[i][0] << " " << res[i][1];  // 최소, 최대 길이
		}

		if (i != N - 1) {
			cout << "\n";
		}
	}
	
	return 0;
}
