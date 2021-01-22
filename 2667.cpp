#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[25][25];

int mapSize;
int complexSize;
int cnt;

int iCheck[4] = {-1,0,0,1};
int jCheck[4] = {0,-1,1,0};

vector<int> v;

void search(int i, int j){
    int nextI, nextJ;
    for(int k = 0 ; k < 4 ; k++){
        nextI = i + iCheck[k]; nextJ = j + jCheck[k];
        if(nextI >= 0 && nextI < mapSize && nextJ >= 0 && nextJ < mapSize && map[nextI][nextJ] != 0){
            map[nextI][nextJ] = 0;
            search(nextI, nextJ);
        }
    }
    complexSize++;
}

void dfs(){
    for(int i = 0 ; i < mapSize ; i++){
        for(int j = 0 ; j < mapSize ; j++){
            if(map[i][j] == 1){
                cnt++;
                complexSize = 0;
                map[i][j] = 0;
                search(i,j);
                v.push_back(complexSize);
                
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> mapSize;
    string temp;
    for(int i = 0 ; i < mapSize ; i++){
        cin >> temp;
        for(int j = 0 ; j < mapSize ; j++){
            map[i][j] = temp[j] - '0';
        }
    }
    dfs();
    sort(v.begin(), v.end());
    cout << cnt << "\n";
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << "\n";
    }
    
}