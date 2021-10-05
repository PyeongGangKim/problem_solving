#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int L[21];
int J[21];
int N;
int cache[21][101];

int dp(int person, int l){
    if(person == N) return 0;
    int &res = cache[person][l];

    if(res != -1) return res;
    if(l - L[person] > 0){
        res = dp(person+1, l - L[person]) + J[person];
    }
    res = max(res, dp(person+1,l));
    return res;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> L[i];
    }
    for(int i = 0 ; i < N ; i++){
        cin >> J[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(0,100) << "\n";
}
