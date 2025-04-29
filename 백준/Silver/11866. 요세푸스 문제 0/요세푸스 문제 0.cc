#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;

	vector<int> v;
	vector<int> res;

	int id = 0;
	int size = 0;

	for (int i = 0;i < N;i++) {
		v.push_back(i + 1);
	}

	while (!v.empty()) {
		size = v.size();
		id += K-1;
		while (id >= size) {
			id -= size;
		}
		res.push_back(v.at(id));
		v.erase(v.begin() + id);
	}

	cout << "<";
	for (int i = 0;i < res.size()-1;i++) {
		cout << res.at(i) << ", ";
	}
	cout << res.at(res.size() - 1) << ">";

	return 0;
}
