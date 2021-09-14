#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<int,int> > v;
int cache[1001][16][16];
int N = 0; 
int dp(int idx, int whiteNum, int blackNum){
    if(whiteNum == 15 && blackNum == 15) return 0;
    if(idx >= N) return 0;
    int &res = cache[idx][whiteNum][blackNum];
    if(res != -1) return res;

    res = dp(idx + 1, whiteNum, blackNum);
    if(whiteNum < 15) res = max(res, dp(idx + 1, whiteNum + 1, blackNum) + v[idx].first);
    if(blackNum < 15) res = max(res, dp(idx + 1, whiteNum , blackNum + 1) + v[idx].second);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int white, black;
    memset(cache, -1, sizeof(cache));
    
    while(cin >> white >> black){
        N++;
        v.push_back(make_pair(white, black));
    }
    cout << dp(0,0,0) << "\n";
}