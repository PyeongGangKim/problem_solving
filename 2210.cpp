#include <iostream>
#include <vector>
#include <string>

using namespace std;

char map[5][5];
vector<string> result;
string sixStr = "000000";

int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};

bool sameStr(){
    for(int i = 0 ; i < result.size() ; i++){
        if(result[i].compare(sixStr) == 0) return false;
    }
    return true;
}

void dfs(int cnt, int x, int y){
    if(cnt == 6){
        if(sameStr()) result.push_back(sixStr);
    }
    else{
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + xCheck[i]; int ny = y + yCheck[i];
            if(nx < 0 || ny < 0 || nx  >= 5 || ny >= 5) continue;
            sixStr[cnt] = map[ny][nx];
            dfs(cnt+1, nx, ny);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            dfs(0,j,i);
        }
    }
    cout << result.size() << "\n";
}