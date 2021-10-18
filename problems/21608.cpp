#include <iostream>
#include <vector>


using namespace std; 

int likes[401][4];
int map[21][21];
int N;
int cntNum[5] = {0,1,10,100,1000};
int mX[4] = {0,0,1,-1};
int mY[4] = {1,-1,0,0};

struct node{
    int emptyRoom;
    int likeRoom;
    int x;
    int y;
    node (int _emptyRoom, int _likeRoom, int _x, int _y){
        emptyRoom = _emptyRoom;
        likeRoom = _likeRoom;
        x = _x;
        y = _y;
    }
};

void searchLoc(int n){
    node maxNode = node(0,0,N,N);
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= N ; j++){
            if(map[i][j] == 0){
                node tempNode = node(0,0,i,j);
                for(int k = 0 ; k < 4 ; k++){
                    int nX = mX[k] + i ; int nY = mY[k] + j;
                    if(nX <= 0 || nX > N || nY <= 0 || nY > N)continue;
                    if(map[nX][nY] == 0){
                        tempNode.emptyRoom++;
                    }
                    else{
                        for(int l = 0 ; l < 4 ; l++){
                            if(map[nX][nY] == likes[n][l]){
                                tempNode.likeRoom++;
                                break;
                            }
                        }
                    }
                }
                if(maxNode.likeRoom < tempNode.likeRoom){
                    maxNode = node(tempNode.emptyRoom, tempNode.likeRoom, tempNode.x, tempNode.y);
                }
                else if(maxNode.likeRoom == tempNode.likeRoom){
                    if(maxNode.emptyRoom < tempNode.emptyRoom){
                        maxNode = node(tempNode.emptyRoom, tempNode.likeRoom, tempNode.x, tempNode.y);
                    }
                    else if(maxNode.emptyRoom == tempNode.emptyRoom){
                        if(maxNode.x > tempNode.x) maxNode = node(tempNode.emptyRoom, tempNode.likeRoom, tempNode.x, tempNode.y);
                        else if(maxNode.x == tempNode.x){
                            if(maxNode.y > tempNode.y) maxNode = node(tempNode.emptyRoom, tempNode.likeRoom, tempNode.x, tempNode.y);
                        }
                    }
                }
            }
        }
    }
    map[maxNode.x][maxNode.y] = n;
}

int Sum(){
    int res = 0;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            int cur = map[i][j];
            int likeNum = 0;
            for(int k = 0 ; k < 4 ; k++){
                int nX = mX[k] + i; int nY = mY[k] + j;
                if(nX <= 0 || nX > N || nY <= 0 || nY > N) continue;
                for(int l = 0 ; l < 4 ; l++){
                    if(map[nX][nY] == likes[cur][l]){
                        likeNum++;
                        break;
                    }
                }
            }
            res += cntNum[likeNum];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N; 

    for(int i = 0 ; i < N*N ; i++){
        int n;
        cin >> n;
        cin >> likes[n][0] >> likes[n][1] >> likes[n][2] >> likes[n][3];
        searchLoc(n);
    }
    cout << Sum() << "\n";

}