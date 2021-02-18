#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int X, Y, rectNum;
int map[101][101];

int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};
int cnt;
int rectSize;
vector<int> rectSizes;

void makeRect(int x1, int y1, int x2, int y2){
    for(int i = y1 ; i < y2 ; i++){
        for(int j = x1 ; j < x2 ; j++){
            map[i][j] = 1;
        }
    }
}

void search(int x, int y){
    int nextX, nextY;
    for(int i = 0 ; i < 4 ; i++){
        nextX = x + xCheck[i]; nextY = y + yCheck[i];
        if(nextX >= 0 && nextX < X && nextY >= 0 && nextY < Y && map[nextY][nextX] == 0){
            map[nextY][nextX] = 1;
            search(nextX, nextY);
        } 
    }
    rectSize++;
}

void dfs(){
    for(int i = 0 ; i < Y ; i++){
        for(int j = 0 ; j < X ; j++){
            if(map[i][j] == 0){
                cnt++;
                map[i][j] = 1;
                search(j,i);
                rectSizes.push_back(rectSize);
                rectSize = 0;
            }
        }        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> Y >> X >> rectNum;
    int x1, x2, y1, y2;
    for(int i = 0 ; i < rectNum ; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        makeRect(x1, y1, x2, y2);
    }
    cnt = 0;
    dfs();
    sort(rectSizes.begin(), rectSizes.end());
    cout << cnt << "\n";
    for(int i = 0 ; i < rectSizes.size() ; i++){
        cout << rectSizes[i] << " ";
    }
    cout << "\n";
}