#include <iostream>
#include <vector>
#include <string>

#define MAX 987654321
using namespace std;

int R, C;
int map[101][101];
vector<pair<int,int> > insaneAdu;
pair<int,int> jongsuAdu;

int mX[] = {1,1,1,0,0,0,-1,-1,-1};
int mY[] = {-1,0,1,-1,0,1,-1,0,1};

int distDiff(int x, int y){
    return abs(jongsuAdu.first - x) + abs(jongsuAdu.second - y);
}
void bomb(){
    vector<pair<int,int> > alive;
    vector<pair<int,int > > bombLoc;
    for(int i = 0 ; i <insaneAdu.size() ; i++){
        if(map[insaneAdu[i].first][insaneAdu[i].second] != 2) bombLoc.push_back(make_pair(insaneAdu[i].first,insaneAdu[i].second));
        else alive.push_back(make_pair(insaneAdu[i].first, insaneAdu[i].second));
    }
    for(int i = 0 ; i < bombLoc.size() ; i++){
        map[bombLoc[i].first][bombLoc[i].second] = 0;
    }
    insaneAdu = alive;

}
bool checkDone(pair<int,int> a){
    if(map[a.first][a.second] == 0 ||  map[a.first][a.second] == 1 || map[a.first][a.second] % 2 == 0 ) return false;
    return true;
}
bool insaneMoveAndCheckDone(){
    for(int i = 0 ; i < insaneAdu.size() ; i++){
        int minDist = distDiff(insaneAdu[i].first,insaneAdu[i].second);
        int idx = 4;
        for(int j = 0 ; j < 10 ; j++){
            int nX = insaneAdu[i].first + mX[j]; int nY = insaneAdu[i].second + mY[j];
            if(nX < 0 || nX >= R || nY <0 || nY >= C) continue;
            int tmp = distDiff(nX,nY);
            
            if(minDist > tmp){
                minDist = tmp;
                idx = j;
            }
        }
        // move
        map[insaneAdu[i].first][insaneAdu[i].second] -= 2;
        map[insaneAdu[i].first + mX[idx]][insaneAdu[i].second + mY[idx]] += 2;
        insaneAdu[i].first += mX[idx]; insaneAdu[i].second += mY[idx];
    }
    for(int i  = 0 ; i < insaneAdu.size() ; i++){
        if(checkDone(insaneAdu[i])) return true;
    }
    bomb();
    return false;
}

bool jonsuMoveAndCheckDone(int n){
    int nX = jongsuAdu.first + mX[n] ; int nY = jongsuAdu.second + mY[n];
    map[nX][nY] += 1;
    map[jongsuAdu.first][jongsuAdu.second] -= 1;
    jongsuAdu = make_pair(nX,nY);
    return false;
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        string temp;
        cin >> temp;
        for(int j = 0 ; j < C ; j++){
            if(temp[j] == 'I') {
                map[i][j] = 1;
                jongsuAdu = make_pair(i,j);
            }
            else if(temp[j] == 'R') {
                map[i][j] = 2;
                insaneAdu.push_back(make_pair(i,j));
            }
            else map[i][j] = 0;
        }
    }
    string order;
    cin >> order;
    int res = 0;
    bool isDone = false;
    for(int i = 0 ; i < order.length() ; i++){
        res++;
        if(jonsuMoveAndCheckDone((order[i] - '0') - 1)) {
            isDone = true;
            break;
        }
        if(insaneMoveAndCheckDone()){
            isDone = true;
            break;
        }
    }

    if(isDone) cout << "kraj " << res << "\n";
    else{
        for(int i = 0 ; i < R ; i++){
            string tmp = "";
            for(int j = 0 ; j < C ; j++){
                if(map[i][j] == 1) tmp += 'I';
                else if(map[i][j] == 2) tmp += 'R';
                else tmp += '.';
            }
            cout << tmp << "\n";
        }
    }
}