#include <iostream>
#include <cstring>

using namespace std;
int N;
int cache[501][501];
int triangle[501][501];
int dp(int i, int j){
    if(i == N) return triangle[i][j];
    int& res = cache[i][j];
    if(res != -1) return res;
    res = max(dp(i+1,j), dp(i+1,j+1)) + triangle[i][j];
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= i ; j++){
            cin >> triangle[i][j];
        }
    }
    memset(cache, -1 ,sizeof(cache));
    cout << dp(1,1) << "\n";
}