#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int cache[101];
int N;
vector<pair<int, int> > v;
int dp(int n){
    int& res = cache[n];
    if(res != -1) return res;
    res = 1;
    for(int i = n+1 ; i < N ; i++){
        if(v[n].second < v[i].second) res = max(res, dp(i)+1);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N;

    for(int i = 0 ; i < N ; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back(make_pair(temp1,temp2));
    }    
    memset(cache,-1,sizeof(cache));
    sort(v.begin(),v.end());
    int res = 0;
    for(int i = 0 ; i < N ; i++){
        res = max(res, dp(i));
    }
    cout << N-res << "\n";
}