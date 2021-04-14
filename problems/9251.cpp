#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;
    int size_1 = str1.length();
    int size_2 = str2.length();

    int dp[size_1 + 1][size_2 + 1];
    for(int i = 0 ; i <= size_1 ; i++) dp[i][0] = 0;
    for(int i = 0 ; i <= size_2 ; i++) dp[0][i] = 0;

    for(int i = 1 ; i <= size_1 ; i++){
        for(int j = 1 ; j <= size_2 ; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[size_1][size_2] << "\n";
}