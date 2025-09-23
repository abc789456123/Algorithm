#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//2진수로 변환하는 함수 뒤집어진 채로 반환됨
string ten_to_two(long long x){
    if (x == 0) return "0";
    string res = "";
    while(x>0){
        char num = x%2+'0';
        res.push_back(num);
        x/=2;
    }
    res.push_back('0');
    //reverse(res.begin(), res.end());
    return res;
}

//f(x)구하는 함수
long long cal_func(long long x){
    long long res = 0;
    string sx = ten_to_two(x);
    string sres = sx;
    for(int i=0;i<sres.size();i++){
        if(i==0&&sres[i]=='0') {
            sres[i]='1';
            break;
        }
        else if(sres[i]=='0'){
            sres[i-1] = '0';
            sres[i] = '1';
            break;
        }
    }
    for(int i=0;i<sres.size();i++){
        if(sres[i]=='1') res += pow(2,i);
    }
    return res;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i=0;i<numbers.size();i++){
        answer.push_back(cal_func(numbers[i]));
    }
    return answer;
}