#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, K;
int nums[200001];
int check[100001];
int maxLen = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];  
    }
    int start, end;
    start = 0; end = 0;
    memset(check, 0, sizeof(check));
    check[nums[end]]++;
    while(start <= end){
        if(end == N) break;
        if(check[nums[end]] > K){
            check[nums[start]]--;
            start++;
        }
        else {
            maxLen = max(maxLen, end - start + 1);
            end++;
            check[nums[end]]++;
        }
         
   }
    cout << maxLen << "\n";
}