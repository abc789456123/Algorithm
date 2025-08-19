#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
tangerine 정렬
tang_size에 첫요소부터 개수를 넣음
tang_size를 정렬하여 가장 큰 요소부터 더해서 몇개의 요소를 넣어야 k를 넘는지 계산
*/

const int MAX_LEN = 100000;
int tang_num[MAX_LEN] = { 0 };

void get_tang_num(vector<int> tangerine) {
    int len = tangerine.size();
    int index = 0;
    tang_num[index]++;
    for (int i = 1; i < len; i++) {
        if (tangerine[i] == tangerine[i - 1]) {
            tang_num[index]++;
        }
        else {
            index++;
            tang_num[index]++;
        }
    }

}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());
    get_tang_num(tangerine);
    sort(tang_num, tang_num+MAX_LEN, greater<int>());

    int sum = 0;
    int n = 0;
    while (sum < k) {
        sum += tang_num[n];
        n++;
        answer++;
    }

    return answer;
}
