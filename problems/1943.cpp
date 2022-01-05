#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
bool dp[50001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int tc = 3;
    while(tc--){
        vector<pair<int,int> > v;
        memset(dp, false,sizeof(dp));
        cin >> N;
        int sum = 0;
        for(int i = 0 ; i < N ; i++){
            int coin, num;
            cin >> coin >> num;
            sum += coin * num;
            v.push_back(make_pair(coin,num));
        }
        if(sum % 2 == 1){
            cout << "0\n";
            continue; 
        }
        dp[0] = true;
        for(int i = 0 ; i <= v[0].second ; i++){
            if(v[0].first * i > sum/2) break;
            dp[v[0].first * i] = true;
        }

        for(int i = 1 ; i < N ; i++){
            for(int j = sum/2 ; j >= 0 ; j--){
                if(!dp[j]) continue;
                for(int k = 1 ; k <= v[i].second ; k++){
                    if(j+k * v[i].first > sum / 2) break;
                    dp[j+k * v[i].first] = true;
                }
                if(dp[sum/2]) break;
            }    
            if(dp[sum/2]) break;
        }
        cout << dp[sum/2] << "\n";
        
    }
}