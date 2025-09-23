#include <string>
#include <vector>

using namespace std;

bool size_check(vector<int> &wallet, vector<int> &bill){
    if(wallet[0]>=bill[0]&&wallet[1]>=bill[1]) return true;
    else if(wallet[1]>=bill[0]&&wallet[0]>=bill[1]) return true;
    else return false;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while(!size_check(wallet, bill)){
        if(bill[0]>=bill[1]) bill[0] /= 2;
        else bill[1] /= 2;
        answer++;
    }
    return answer;
}