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

	//입력 받기 
	int N;
	cin >> N;
	int* fu = new int[N];

	for (int i = 0;i < N;i++) {
		cin >> fu[i];
	}

	int res = 0;
	int flag = 0;
	map<int, int> count;

	int left = 0, right = 0;
	
	while (right<N) {
		count[fu[right]]++;
		right++;
		
		while (count.size() > 2) {
			count[fu[left]]--;
			if (count[fu[left]] == 0) count.erase(fu[left]);
			left++;
		}
		res = max(res, right - left);
	}
	
	std::cout << res;

	delete[] fu;

	return 0;
}
