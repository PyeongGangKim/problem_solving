#include <iostream>
#include <cstring>

#define MAX 1025

using namespace std;

int map[MAX][MAX];
int sum[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> map[i][j];
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + map[i][j];
        }
    }
    for(int i = 0 ; i < M ; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1] << "\n";
    }

}
