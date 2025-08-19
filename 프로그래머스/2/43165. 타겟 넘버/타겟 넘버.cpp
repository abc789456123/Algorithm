#include <string>
#include <vector>

using namespace std;

/*
0으로 시작
numbers의 첫 요소를 +한 요소, -한 요소로 분리
numbers의 그 다음 요소를 +한 요소, -한 요소로 분리
*/


int solution(vector<int> numbers, int target) {
    int answer = 0;
    int len = numbers.size();

    vector<vector<int>> sum(len, vector<int>());
    sum[0].push_back(numbers[0]);
    sum[0].push_back((-1) * numbers[0]);
    for (int i = 1; i < len; i++) {
        int len2 = sum[i - 1].size();
        int num = numbers[i];
        for (int j = 0; j < len2; j++) {
            sum[i].push_back(sum[i-1][j] + num);
            sum[i].push_back(sum[i-1][j] - num);
        }
    }

    vector<int> res = sum[len - 1];

    for (int i = 0; i < res.size(); i++) {
        if (res[i] == target) answer++;
    }

    return answer;
}