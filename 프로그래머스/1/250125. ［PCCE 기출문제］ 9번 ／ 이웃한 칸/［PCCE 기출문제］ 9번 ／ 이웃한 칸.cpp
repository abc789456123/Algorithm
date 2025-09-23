#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int dh, dw;
    for(int i=0;i<4;i++){
        dh=h+dx[i];
        dw=w+dy[i];
        if(dh>=0&&dh<board.size()&&dw>=0&&dw<board.size()&&board[h][w]==board[dh][dw]){
            answer++;
        }
    }
    return answer;
}