#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int map[51][51][2];
vector<pair<int,int> > airCleaner;
int R,C,T;
int cur = 0;

int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};

bool isAirCleaner(int i, int j){
    if((airCleaner[0].first == i && airCleaner[0].second == j) || (airCleaner[1].first == i && airCleaner[1].second == j)) return true;
    return false;

}
void spread(){
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            if(map[i][j][cur] < 5) {
                map[i][j][cur^1] += map[i][j][cur];
                map[i][j][cur] = 0; 
                continue;
            }
            if(isAirCleaner(i,j))continue;
            int cnt = 0;
            vector<pair<int,int> > spreadLoc;
            for(int k = 0 ; k < 4 ; k++){
                int nextX = i + moveX[k]; int nextY = j + moveY[k];
                if(nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
                if(isAirCleaner(nextX,nextY)) continue;
                // cout << i << " " << j << " " << nextX << " " << nextY << "\n";
                cnt++;
                spreadLoc.push_back(make_pair(nextX,nextY));
            }
            int spreadSize = map[i][j][cur] / 5;
            for(int i = 0 ; i < cnt ; i++){
                map[spreadLoc[i].first][spreadLoc[i].second][cur^1] += spreadSize;
                // cout << spreadLoc[i].first << " " << spreadLoc[i].second << " " << map[spreadLoc[i].first][spreadLoc[i].second][cur^1] << "\n";
            }
            map[i][j][cur^1] += map[i][j][cur] - spreadSize * cnt;

            // cout << i << " " << j << " " << map[i][j][cur] - spreadSize * cnt << "\n";
            map[i][j][cur] = 0;
        }
    }
    cur = cur^1;


}
void spreadByAirClearner(){
    int temp = 0;
    int prev = 0;
    int clockX = airCleaner[0].first; int clockY = airCleaner[0].second;
    int reverseClockX = airCleaner[1].first ; int reverseClockY = airCleaner[1].second;
    for(int i = 1 ; i < C ; i++){ // 시계 방향 처음 오른쪽으로 가기
        temp = map[clockX][i][cur];
        map[clockX][i][cur] = prev;
        prev = temp;
    }
    for(int i = clockX - 1; i >= 0 ; i--){ // 시계 방향 위쪽으로 가기
        temp = map[i][C-1][cur];
        map[i][C-1][cur] = prev;
        prev = temp;
    }
    for(int i = C-2 ; i >= 0 ; i--){ // 시계 방향 왼쪽으로 가기
        temp = map[0][i][cur];
        map[0][i][cur] = prev;
        prev = temp;
    }
    for(int i = 1 ; i < clockX ; i++){
        temp = map[i][0][cur];
        map[i][0][cur] = prev;
        prev = temp;
    }
   
    temp = 0;
    prev = 0;
    for(int i = 1 ; i < C ; i++){ // 반시계 방향 처음 오른쪽으로 가기
        temp = map[reverseClockX][i][cur];
        map[reverseClockX][i][cur] = prev;
        prev = temp;
    }
    for(int i = reverseClockX + 1; i < R ; i++){ // 반시계 방향 아래쪽으로 가기
        temp = map[i][C-1][cur];
        map[i][C-1][cur] = prev;
        prev = temp;
    }
    for(int i = C-2 ; i >= 0 ; i--){ // 반시계 방향 왼쪽으로 가기
        temp = map[R-1][i][cur];
        map[R-1][i][cur] = prev;
        prev = temp;
    }
    for(int i = R-2 ; i > reverseClockX ; i--){
        temp = map[i][0][cur];
        map[i][0][cur] = prev;
        prev = temp;
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> T;

    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin >> map[i][j][cur];
            if(map[i][j][cur] == -1){
                map[i][j][cur] = 0;
                airCleaner.push_back(make_pair(i,j));
            }
            else{

            }
        }
    }
    for(int i = 0 ; i < T ; i++){
        spread();
        spreadByAirClearner();
    }
    int res = 0;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            // cout << map[i][j][cur] << " ";
            res += map[i][j][cur] ;
        }
        // cout << "\n";
    }
    cout << res << "\n";

}