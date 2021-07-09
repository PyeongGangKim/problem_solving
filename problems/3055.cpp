#include <iostream>
#include <queue>
#include <string>

using namespace std;
int R, C;
int map[51][51];
int s_x, s_y;
int w_x , w_y ;
int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};
int result = 0;
queue<pair<int, pair<int,int> > > s_q, w_q;
bool bfs(){
    
    
    

    
    int time = 0;
    while(!s_q.empty()){
        while(!w_q.empty() && w_q.front().first <= time){
            int num = s_q.front().first;
            int cur_x = w_q.front().second.first, cur_y = w_q.front().second.second;
            //cout << "w " <<  num << " " << cur_x << " " << cur_y << "\n";
            w_q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int next_x = cur_x + moveX[i], next_y = cur_y + moveY[i];
                
                if(next_x >= R || next_x < 0 || next_y >= C || next_y < 0) continue; // 범위 체크
                if(map[next_x][next_y] == -1 || map[next_x][next_y] == -2 || map[next_x][next_y] == 1) continue; // 물이 들어갈 곳에 동굴또는 돌 아니면 이전에 방문한 곳이면 패스
                w_q.push(make_pair(num+1,make_pair(next_x, next_y)));
                map[next_x][next_y] = -2;
            }
        }
        while(!s_q.empty() && s_q.front().first <= time){
            int num = s_q.front().first;
            int cur_x = s_q.front().second.first, cur_y = s_q.front().second.second;
            //cout << "s " <<  num << " " << cur_x << " " << cur_y << "\n";
            s_q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int next_x = cur_x + moveX[i], next_y = cur_y + moveY[i];
                //cout << "s " <<  num << " " << next_x << " " << next_y << " " << map[next_x][next_y] << "\n";
                if(next_x >= R || next_x < 0 || next_y >= C || next_y < 0) continue; // 범위 체크
                if(map[next_x][next_y] == -1 || map[next_x][next_y] == -2 || map[next_x][next_y] == 2) continue;// 도치가 갈 곳이 물이거나 이전에 간 곳이거나 돌이면 패스
                s_q.push(make_pair(num+1,make_pair(next_x, next_y)));
                if(map[next_x][next_y] == 1){
                    result = num + 1;
                    return true;
                }
                map[next_x][next_y] = 2;
            }

        }
        time++;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> R >> C;
    string str;
    for(int i = 0 ; i < R ; i++){
        cin >> str;
        for(int j = 0 ; j < C ; j++){
            if(str[j] == '.'){
                map[i][j] = 0;
            }
            else if(str[j] == 'D'){
                map[i][j] = 1;
            }
            else if(str[j] == 'X'){
                map[i][j] = -1;
            }
            else if(str[j] == '*'){
                map[i][j] = -2;
                w_x = i;
                w_y = j;
                
                w_q.push(make_pair(0,make_pair(w_x,w_y)));
            }
            else{
                map[i][j] = 2;
                s_x = i;
                s_y = j;
                s_q.push(make_pair(0,make_pair(s_x,s_y)));
            }
        }
    }
    if(bfs()) cout << result << "\n";
    else cout << "KAKTUS\n"; 

}