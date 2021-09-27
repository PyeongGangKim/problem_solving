#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001
typedef long long ll;

int nums[MAX];
int sum[2][MAX];
int res[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
    }

    for(int i = 0 ; i < N ; i++){
         if((i + 1) % 2 == 0) sum[0][i/2+1] = sum[0][i/2] + nums[i]; 
        else sum[1][i/2+1] = sum[1][i/2] + nums[i]; 
    }
    int maxNum = -1;
    for(int i = 1 ; i <= N ; i ++){
        int idx = i / 2 + 1;
            // 짝수일 경우
        if(i % 2 == 0) res[i] = sum[1][idx -1] + (sum[0][N/2-1] - sum[0][idx-2]);  
            // 홀수일 경우
        else res[i] = sum[1][idx-1] + (sum[0][N/2-1] - sum[0][idx-1]) + nums[N - 1];
                
        maxNum = max(maxNum, res[i]);
        
    }

    cout << maxNum << "\n";
}