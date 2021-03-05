#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> tree;
long long N, M;
bool isPossible(long long height){
    long long len = 0;
    for(long long i = 0 ; i < N ; i++){
        if(tree[i] - height > 0){
            len += tree[i] - height; 
        }
    
    }

    if(len >= M) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M;
    long long temp;
    long long low = 0;
    long long high = -1;
    for(long long i = 0 ; i < N ; i++){
        cin >> temp;
        tree.push_back(temp);
        
        high = max(high, temp);

    }
    long long mid;
    long long result = 0;
    while(low <= high){
        mid = (high + low) / 2;
        if(isPossible(mid)){
            result = max(result , mid);
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << result << "\n";

}