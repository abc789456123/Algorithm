#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits> // INT_MAX 사용

using namespace std;

int N = 0, K = 0, P = 0, X = 0;

/*
1층부터 N층까지 이용이 가능한 엘리베이터가 있다.
엘리베이터의 층수를 보여주는 디스플레이에는 K개의 fnd가 있다. 수는 0으로 시작할 수도 있다.
엘리베이터 디스플레이의 LED 중에서 최소 1개, 최대 P개를 반전
*/
int fnd[10][7] = { 
	{1,1,1,0,1,1,1},				// 0
	{0,0,1,0,0,1,0},				// 1
	{1,0,1,1,1,0,1},				// 2
	{1,0,1,1,0,1,1},				// 3
	{0,1,1,1,0,1,0},				// 4
	{1,1,0,1,0,1,1},				// 5
	{1,1,0,1,1,1,1},				// 6
	{1,0,1,0,0,1,0},				// 7
	{1,1,1,1,1,1,1},				// 8
	{1,1,1,1,0,1,1}					// 9
};
string conv_int_str(int N, int num) {
	string res = to_string(num);
	while (res.size() < N) {
		res = '0' + res;
	}
	return res;
}
int count_led(char ci, char cx) {
	int i = ci - '0';
	int x = cx - '0';
	int* fi = fnd[i];
	int* fx = fnd[x];
	int res = 0;
	for (int j = 0; j < 7; j++) {
		if (fi[j] != fx[j]) {
			res++;
		}
	}
	return res;
}


int main() {
	// 빠른 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력
	cin >> N >> K >> P >> X;
	string ki, kx;
	kx = conv_int_str(K, X);
	// 로직
	int res = 0, cnt;	// 헷갈리는 숫자 카운트
	for (int i = 1; i <= N; i++) {
		// X == i일때는 제외
		if (X == i)continue;

		// 1부터 N까지 순환하는 i를 K자리 숫자(string)로 표기
		ki = conv_int_str(K, i);
		cnt = 0;

		// X를 i로 바꾸는데 반전해야하는 LED 개수 구하기
		for (int j = 0; j < K; j++) {
			if (kx[j] != ki[j]) {
				// kx[j]를 k[i]로 바꾸는데 드는 LED 개수 구하기
				cnt += count_led(kx[j], ki[j]);
			}
		}
		// 개수가 1~2개면 res++;
		if (cnt <= P) {
			res++;
		}
	}



	// 출력
	cout << res;


	return 0;
}
