#include <iostream>
#include <cstring>


using namespace std;
int N,M;
bool check[301][301];
int graph[301][301];
int xMove[4] = {-1,1,0,0};
int yMove[4] = {0,0,1,-1};

void checkGraph(){
    int copyGraph[301][301];
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            copyGraph[i][j] = graph[i][j];
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int zeroNum = 0;
            if(graph[i][j] == 0) continue;
            for(int k = 0 ; k < 4 ; k++){
                int nextX = i + xMove[k]; int nextY = j + yMove[k];
                if(nextX >= N || nextY >= M || nextX < 0 || nextY < 0) continue;
                if(copyGraph[nextX][nextY] == 0) zeroNum++;
            }
            int temp = graph[i][j] - zeroNum;
            graph[i][j] = (temp < 0) ? 0 : temp;
        }
    }
}
void dfs(int x, int y){
    for(int i = 0 ; i < 4 ; i++){
        int nextX = x + xMove[i]; int nextY = y + yMove[i];
        if(nextX >= N || nextY >= M || nextX < 0 || nextY < 0 || check[nextX][nextY] || graph[nextX][nextY] == 0) continue;
        check[nextX][nextY] = true;
        dfs(nextX, nextY);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ;  j < M ; j++){
            cin >> graph[i][j];
        }
    }
    int cnt = 0;
    while(1){
        int island_num = 0;
        memset(check,false, sizeof(check));
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(graph[i][j] != 0 && !check[i][j]){
                    island_num++;
                    dfs(i,j);
                }
            }
        }
        if(island_num == 0){
            cout << "0\n";
            break;
        }
        if(island_num >= 2){
            cout << cnt << "\n";
            break;
        }
        checkGraph();
        cnt++;
    }

}