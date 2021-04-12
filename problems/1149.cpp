#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int N;
    cin >> N;
    int DP[N][3];
    int value[3];
    cin >> DP[0][0] >> DP[0][1] >> DP[0][2];

    for(int i = 1 ; i < N ; i++){
        cin >> value[0] >> value[1] >> value[2];
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + value[0];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + value[1];
        DP[i][2] = min(DP[i-1][0], DP[i-1][1]) + value[2];
    }
    cout << min(DP[N-1][0],min(DP[N-1][1],DP[N-1][2])) << "\n";

}