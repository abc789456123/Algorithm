#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>

using namespace std;

//산술평균, 최빈값 출력
void cal(vector<int> v, int N, vector<int>& res) {
	vector<int> third;
	int mint = *max_element(v.begin(), v.end());

	int mid = (N / 2) + 1;
	int cnt = 0;
	int ires = -10000;

	double avg = 0;
	for (int i = 0;i < 8001;i++) {

		if (v.at(i) != 0) {
			//산술평균
			avg += ((i-4000) * v.at(i) / static_cast<double>(N));

			//중앙값
			cnt += v.at(i);
		}
		if (ires==-10000 && cnt >= mid) {
			ires = (i-4000);
		}

		//최빈값
		if (third.size() < 2 && v.at(i) == mint) {
			third.push_back(i-4000);
		}
	}
	res.at(0) = round(avg);
	res.at(1) = ires;
	third.size()==2 ? res.at(2) = third.at(1) : res.at(2) = third.at(0);
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력 받기 
	int N=0;
	int min = 4000;
	int max = -4000;
	cin >> N;
	vector<int> v(8001, 0);
	vector<int> res(3, 0);
	int a = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.at(a+4000)++;
		if (a < min) {
			min = a;
		}
		if (a > max) {
			max = a;
		}
	}
	cal(v, N, res);
	for (int i = 0;i < 3;i++) {
		cout << res[i] << "\n";
	}
	cout << max - min << "\n";


	return 0;


}
