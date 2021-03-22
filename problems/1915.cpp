#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string temp;
    int N, M;
    cin >> N >> M;
    int map[N][M];
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        for(int j = 0 ; j < M ; j++){
            map[i][j] = temp[j] - '0';
        }
    }
    int maxNum = map[0][0];
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M ; j++){
            if(i - 1 >= 0 && j - 1 >= 0 && map[i][j] != 0 ){
                map[i][j] = min( map[i-1][j-1], min(map[i][j-1], map[i-1][j])) + 1;
                maxNum = max(maxNum, map[i][j]);
            }
        }
    }
    cout << maxNum*maxNum << "\n";
}