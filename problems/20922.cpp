#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, K;
int nums[200001];
int check[100001];
int maxLen = -1;
bool checkLen(int start, int end){
    for(int i = start ; i <= end ; i++){
        check[nums[i]] += 1;
        if(check[nums[i]] > K) return false;
    }
    maxLen = max(maxLen, end - start + 1);
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];  
    }
    int start, end;
    start = 0; end = 0;
    while(start <= end){
        if(end == N) break;
        memset(check, 0, sizeof(check));
        bool isPossible = checkLen(start, end);
        if(isPossible) end++;
        else start++;
    }
    cout << maxLen << "\n";
}