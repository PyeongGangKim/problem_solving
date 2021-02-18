#include <iostream>
#include <algorithm>

using namespace std;

char map[2202][2202];

void divide(int x, int y, int n){
    if(n==1) map[y][x] = '*';
    else{
        n = n/3;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(i == 1 && j ==1) continue;
                divide(x + j*n, y + i*n, n);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    fill(&map[0][0], &map[N+1][N+1],' ');
    divide(0, 0, N);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }

}