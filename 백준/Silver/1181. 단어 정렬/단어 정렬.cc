#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<vector<string>> strV(51);
	string str;
	vector<string> temp;

	int N;
	int index;
	cin >> N;
	for (int i = 0; i < N;i++) {
		cin >> str;
		index = str.size();
		strV[index].push_back(str);
	}
	for (vector<string>v : strV) {
		if (!v.empty()) {
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());

			for (int i = 0;i < v.size();i++) {
				cout << v[i] <<"\n";
			}
		}
	}
	
}
