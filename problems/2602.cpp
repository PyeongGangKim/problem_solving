#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string standard;
string angel;
string devil;

int cache[101][21][2];

int std_len;
int angel_len;

int dp(int dol, int st, bool turn){
    if(st == std_len) return 1;
    if( dol >= angel_len) return 0;
    int &res = cache[dol][st][turn];
    if(res != -1) return res;

    res = 0;
    
    if(turn){ // devil이라면
        for(int i = dol ; i < angel_len ; i++){
            if(devil[i] == standard[st]){
                res += dp(i+1, st+1, !turn);
            }
        }
    }
    else{ // angel이라면
        for(int i = dol ; i < angel_len ; i++){
            if(angel[i] == standard[st]){
                res += dp(i+1, st+1, !turn);
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> standard;
    cin >> devil;
    cin >> angel;

    memset(cache, -1, sizeof(cache));
    std_len = standard.length();
    angel_len = angel.length();
    cout << dp(0,0,0) + dp(0,0,1) << "\n";
}