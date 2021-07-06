#include <iostream>

using namespace std;
long long cache[201][201];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int K, N;
    cin >> N >> K;
    for(int i = 0 ; i <= N ; i++){
        cache[1][i] = 1;
        cache[2][i] = i + 1;
    }

    for(int i = 3 ; i <= K ; i++){
        for(int j =  0 ; j <= N ; j++){
            for(int k = 0 ; k <= j ; k++){
                cache[i][j] = (cache[i][j] + cache[i-1][j-k]) % 1000000000;
            }
        }
    }
    cout << cache[K][N] << '\n';
}