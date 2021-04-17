#include <iostream>
#include <cstring>

using namespace std;
int N;
int cache[100001][3];
int dp(){
    cache[1][0] = 1 ; cache[1][1] = 1; cache[1][2] = 1;
    for(int i = 2 ; i <= N ; i++){
        cache[i][0] = (cache[i-1][0]+ cache[i-1][1] + cache[i-1][2]) % 9901;
        cache[i][1] = (cache[i-1][0]+ cache[i-1][2] ) % 9901;
        cache[i][2] = (cache[i-1][0]+ cache[i-1][2]) % 9901;
    }
    return (cache[N][0]+ cache[N][1] + cache[N][2]) % 9901;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    cin >> N; 
    cout << dp() << "\n";
}