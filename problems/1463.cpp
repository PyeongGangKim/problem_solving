#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int cache[1000001];
    int N;
    cin >> N;
    for(int i = 0 ; i <= N ; i++){
        cache[i] = 987654321;
    }
    cache[N] = 0;
    for(int i = N ; i > 0 ; i--){
        if(i%3 == 0){
            cache[i/3] = min(cache[i/3], cache[i] + 1);
        }
        if(i%2 == 0){
            cache[i/2] = min(cache[i/2], cache[i] + 1);
        }
        cache[i-1] = min(cache[i-1], cache[i] + 1);
    }
    cout << cache[1] << "\n";
}