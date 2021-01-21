#include <iostream>
#include <vector>

using namespace std;

bool farm[50][50] ={false,};
int W, H, cabbageNum;
int testcase;
int checkNum;
int wCheck[4] = {-1,0,0,1};
int hCheck[4] = {0,-1,1,0};

void search(int h, int w){
    int nextW, nextH;
    for(int i = 0 ; i < 4 ; i++){
        nextW = w + wCheck[i]; nextH = h + hCheck[i];
        if(nextW >= 0 && nextH >= 0 && nextW < W && nextH < H && farm[nextH][nextW]){
            farm[nextH][nextW] = false;
            search(nextH, nextW);
        }
    }
}
int dfs(){
    int cnt = 0;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            if(farm[i][j]){
                cnt++;
                farm[i][j] = false;
                search(i, j);
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> testcase;
    int w, h;
    for(int i = 0 ; i < testcase ; i++){
        cin >> W >> H >> cabbageNum;
        for(int i = 0 ; i < cabbageNum ; i++){
            cin >> w >> h;
            farm[h][w] = true;
        }
        cout << dfs() << "\n";
    }

}