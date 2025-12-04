#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

int N, M, S, R, C;


int main()
{
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> N;
	vector<pair<string, int>> v;
	vector<string> v_origin;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back({ str, i });
		v_origin.push_back(str);
	}
	sort(v.begin(), v.end());
	int simil = 0;
	pair<string, int> p1, p2;
	// 최대 유사도 구하기
	for (int i = 0; i < N - 1; i++) {
		bool flag = true;
		p1 = v[i];
		p2 = v[i + 1];
		int len = min(p1.first.size(), p2.first.size());
		if (simil >= len) continue;
		for (int j = 0; j < len; j++) {
			if (p1.first[j] != p2.first[j]) {
				flag = false;
				if (j > simil) {
					simil = j;
				}
				break;
			}
		}
		if (flag == true && len != max(p1.first.size(), p2.first.size()) && len > simil) {
			simil = len;
		}
	}
	// 최대 유사도에 해당하는 모든 요소 구하기
	int index = N - 1;
	for (int i = 0; i < N - 1; i++) {
		bool flag = true;
		p1 = v[i];
		p2 = v[i + 1];
		int len = min(p1.first.size(), p2.first.size());
		if (simil > len) continue;
		for (int j = 0; j < len; j++) {
			if (p1.first[j] != p2.first[j]) {
				flag = false;
				if (j == simil) {
					index = min({ index, p1.second, p2.second });
				}
				break;
			}
		}
		if (flag == true && len == simil) {
			index = min({ index, p1.second, p2.second });
		}
	}
	vector<string> res;
	str = v_origin[index];
	res.push_back(str);
	// 두번째 요소 찾기
	for (int i = 0; i < N; i++) {
		bool flag = true;
		if (res.size() == 2)break;
		if (i == index) continue;
		string str2 = v_origin[i];
		for (int j = 0; j < min(str.size(), str2.size()); j++) {
			if (str[j] != str2[j]) {
				flag = false;
				if(j == simil) res.push_back(str2);
				break;
			}
		}
		if (flag == true && min(str.size(), str2.size()) == simil) {
			res.push_back(str2);
			break;
		}
	}


	// 출력
	if (simil == 0) {
		cout << v_origin[0] << "\n" << v_origin[1];
	}
	else {
		cout << res[0] << "\n" << res[1];
	}

	return 0;
}
