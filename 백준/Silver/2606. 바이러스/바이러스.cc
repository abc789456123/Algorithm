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
	cin >> N;
	cin >> M;
	vector<vector<int>> v(N + 1);
	
	int a = 0, b = 0;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> vir;
	vir.push(1);
	int id;
	vector<int> save(N + 1, 0);
	save[1] = 1;
	int cnt = 0;

	while (!vir.empty()) {
		id = vir.front();
		for (int i = 0;i < v.at(id).size();i++) {
			a = v.at(id).at(i);
			if (save.at(a) == 0){
				vir.push(a);
				save.at(a) = 1;
				cnt++;
			}
			
		}
		vir.pop();
	}

	cout << cnt;
	return 0;
}
