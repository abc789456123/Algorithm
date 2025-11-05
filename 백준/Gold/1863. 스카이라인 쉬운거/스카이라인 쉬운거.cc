#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits> // INT_MAX 사용
#include <cmath>

using namespace std;

int N, L, R, C;

int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	stack<int> s1;
	stack<int> s2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		s1.push(R);
	}    
	
	int res = 0;
	// 아무것도 없을 때
	if (s1.empty()) {
		cout << 0;
		return 0;
	}


	while (!s1.empty()) {
		// 빈 공간은 거르기
		int top1 = s1.top();
		s1.pop();

		if (s2.empty() || top1 > s2.top()) {
			if(top1 != 0) s2.push(top1);
		}
		else {
			while (!s2.empty() && top1 < s2.top()) {
				res++;
				s2.pop();
			}
			if (top1 != 0 && (s2.empty() || s2.top() < top1)) s2.push(top1);
		}
	}
	while (!s2.empty()) {
		s2.pop();
		res++;
	}


	// 출력
	cout << res;

	return 0;
}
/*
맨 오른쪽이 top

루프1
1 2 1 3 1 0 2 3 2
                1

루프2
1 2 1 3 1 0 2 3
		    1 2

루프3
!!! s2의 top이 더 큼 !!!
1 2 1 3 1 0 2
        1 2 3
	res++ -> res==1
1 2 1 3 1 0 2
		  1 2
	s1이 다시 커졌으니 pop

루프4
!!! s2의 top이 더 큼 !!!
1 2 1 3 1 0
		1 2
	res++ -> res==2

	res++ -> res==3
1 2 1 3 1 0

루프5
!!! 0은 s2에 넣지 않음 !!!
1 2 1 3 1

루프6
1 2 1 3
      1

루프7
!!! s2의 top이 더 큼 !!!
1 2 1
  1 3
	res++ -> res==4
루프8
1 2
1 1 

루프9
!!! s2의 top이 더 큼 !!!
1
1 1 2
	res++ -> res==5


*/