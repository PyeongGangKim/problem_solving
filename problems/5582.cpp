#include <iostream>
#include <string>
#include <algorithm>

#define MAX 4001

using namespace std;

int dp[MAX][MAX];
int res = -1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1;
    string str2;
    cin >> str1 >> str2;

    for(int i = 0 ; i < str1.length() ; i++){
        if(str2[0] == str1[i])dp[0][i] = 1;
    }
    for(int i = 0 ; i < str2.length() ; i++){
        if(str1[0] == str2[i]) dp[i][0] = 1;
    }

    for(int i = 1 ; i < str2.length() ; i++){
        for(int j = 1 ; j < str1.length() ; j++){
            if(str2[i] == str1[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                res = max(dp[i][j], res);
            }
        }
    }
    if(res == -1) res = 0;
    cout << res << "\n";
}