#include <iostream>

using namespace std;

int map[101][101];
int check[101][101] = {0,};

int mapSize;
int flowHeight;
int regionNum = 0;
int maxRegionNum = 1;

int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};

void search(int m, int n){
    int nextM, nextN;
    for(int i = 0 ; i < 4 ; i++){
        nextM = m + xCheck[i]; nextN = n + yCheck[i];
        if(nextM < 0 || nextM >= mapSize || nextN < 0 || nextN >= mapSize) continue;
        if(check[nextM][nextN] != 0 || map[nextM][nextN] <= flowHeight) continue;
        
        check[nextM][nextN] = 1;
        search(nextM, nextN);
        
    }
}
void dfs(){
    for(int m = 0 ; m < mapSize ; m++){
        for(int n = 0 ; n < mapSize ; n++){
            if(map[m][n] > flowHeight && check[m][n] == 0){
                check[m][n] = 1;
                search(m,n);
                regionNum++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> mapSize;
    int minHeight = 101; int maxHeight = 0;
    for(int i = 0 ; i < mapSize ; i++){
        for(int j = 0 ; j < mapSize ; j++){
            cin >> map[i][j];
            if(minHeight > map[i][j]) minHeight = map[i][j];
            if(maxHeight < map[i][j]) maxHeight = map[i][j];
        }
    }
    for(int i = minHeight ; i < maxHeight ; i++){
        flowHeight = i;
        regionNum = 0;
        dfs();
        if(maxRegionNum < regionNum) maxRegionNum = regionNum;
        for(int m = 0 ; m < mapSize ; m++){// initialize
            for(int n = 0 ; n < mapSize ; n++){
                check[m][n] = 0;
            }
        }
    }
    cout << maxRegionNum << "\n";
}