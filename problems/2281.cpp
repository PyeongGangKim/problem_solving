#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int DP[1001][1001];
int name[1001];

int n, m;
int dp(int index, int curLen){
    if(index >= n) return 0;

    int& res = DP[index][curLen];

    if(res != -1) return res;

    //한칸 내림
    res = (m-curLen+1)*(m-curLen+1) + dp(index + 1, name[index]+1);

    //현재 자리에 그냥 적는 경우
    if(curLen + name[index] <= m){
        res = min(res, dp(index + 1, curLen + name[index] + 1));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        cin >> name[i];
    }
    memset(DP, -1, sizeof(DP));
    if(n == 1) cout << (m-name[0]) * (m-name[0]) << "\n";
    else{
        cout << dp(1, name[0] + 1) << "\n";
    }
}
