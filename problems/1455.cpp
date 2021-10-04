#include <iostream>
#include <string>
using namespace std;

int map[101][101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        string str;
        cin >> str;
        for(int j = 1 ; j <= M ; j++){
            map[i][j] = str[j-1] - '0';
        }
    }
    int n = 0;
    int m = 0;
    int cnt = 0;
    while(1){
        n = 0;
        m = 0;
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= M ; j++){
                if(map[i][j]){
                    if(i*j >= n*m) {
                        n = i;
                        m = j;
                    }
                }
            }
        }
        if(n == 0 && m == 0) break;
        else{
            for(int i = 1 ; i <= n ; i++){
                for(int j = 1 ; j <= m ;j++){
                    if(map[i][j]) map[i][j] = 0;
                    else map[i][j] = 1;
                }
            }
            cnt++;
        }
    }
    cout << cnt << "\n";
}