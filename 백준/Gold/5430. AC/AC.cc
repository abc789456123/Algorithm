#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>

using namespace std;
vector<int> getArr(string arr) {
	int len = arr.size();
	vector<int> res;
	if (len == 2) return res;
	int num = 0;
	string str = "";
	for (int i = 1; i < len - 1; i++) {
		if (arr[i] == ',' && !str.empty()) {
			num = stoi(str);
			res.push_back(num);
			str = "";
		}
		else {
			str += arr[i];
		}
	}
	num = stoi(str);
	res.push_back(num);

	return res;
}

vector<int> cal(vector<int> v, string p) {
	vector<int> res;

	bool flag = true; //true면 정방향, false면 역방향
	for (int j = 0; j < p.size(); j++) {
		if (p[j] == 'R') flag = !flag;
		if (p[j] == 'D') {
			if (v.size() == 0) {
				//불가능하므로 error 출력
				//-1 담은 벡터 리턴
				return { -1 };
			}
			if (flag == true) {
				//첫번째거 삭제
				v.erase(v.begin());
			}
			else {
				//맨 뒤에거 삭제
				v.erase(v.end() - 1);
			}
		}
	}
	if (flag == true) {
		return v;
	}
	else {
		for (int i = v.size() - 1; i >= 0; i--) {
			res.push_back(v[i]);
		}
		return res;
	}
}

int main()
{
	int T;
	cin >> T;
	vector<string> p;
	vector<int> N;
	vector<string> arr;

	string str;
	int a;

	vector<int> v;
	vector<int> calcul;

	for (int i = 0; i < T; i++) {
		cin >> str;
		p.push_back(str);

		cin >> a;
		N.push_back(a);
		cin >> str;
		arr.push_back(str);
	}

	for (int i = 0; i < T; i++) {
		v = getArr(arr[i]);
		calcul = cal(v, p[i]);
		if (!calcul.empty() && calcul[0] == -1) cout << "error\n";
		else if (!calcul.empty() && calcul[0] != -1) {
			cout << "[";
			for (int j = 0; j < calcul.size()-1; j++) {
				cout << calcul[j] << ",";
			}
			cout << calcul[calcul.size() - 1] << "]\n";
		}
		else if (calcul.empty()) {
			cout << "[]\n";
		}
	}

}

