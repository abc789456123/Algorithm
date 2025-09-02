#include <string>
#include <vector>
#include <queue>

using namespace std;
int cal_dis(vector<string> &place, int x, int y){
    pair<int,int> xy;
    queue<pair<int, int>> q;
    vector<vector<int>> save(5, vector<int>(5, 0));
    q.push({x,y});
    save[x][y]=1;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int a,b;
    
    while(!q.empty()){
        xy = q.front();
        a=xy.first;
        b=xy.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = a + dx[i], ny = b + dy[i];
            if(nx<0||nx>=5||ny<0||ny>=5) continue;
            
            if(save[a][b]<3){
                if(save[nx][ny]==0&&place[nx][ny]=='P'){
                    return 0;
                }
                else if(save[nx][ny]==0&&place[nx][ny]=='O'){
                    q.push({nx,ny});
                    save[nx][ny] = save[a][b]+1;
                }
            }
        }
        
    }
    return 1;
    
    
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<string> place;
    int res = 1;
    for(int i=0;i<5;i++){
        place = places[i];
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(place[j][k]=='P'){
                    if(cal_dis(place, j, k)==0) res = 0;
                }
            }
        }
        answer.push_back(res);
        res = 1;
    }
    return answer;
}