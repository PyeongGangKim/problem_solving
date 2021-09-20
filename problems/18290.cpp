#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int N,M,K;
vector<int> nums;

bool check[MAX];
int res = -1000000;

void dfs(int cnt, int cur){
     
    if(cnt == K){
        res = max(res, cur);
    }
    else{
        for(int i = 0 ; i < N*M ; i++){
            if(!check[i]){
                if(i % M != 0){
                    if(i-1 >= 0 &&  check[i-1]) continue;
                }
                if(i % M != M - 1){
                    if( i+1 < N*M && check[i+1]) continue;
                }
                
                if(i-M >= 0 && check[i-M]) continue;
                if(i+M < N*M && check[i+M]) continue;
                check[i] = true;
                dfs(cnt+1, cur+nums[i]);
                check[i] = false;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    int num;
    memset(check, false, sizeof(check));
    for(int i = 0 ; i < N*M ; i++){
        cin >> num;
        nums.push_back(num);
    }
    dfs(0,0);
    cout << res << "\n";

}