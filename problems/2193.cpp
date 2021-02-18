#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int N;
    cin >> N;
    long long cache[N+1];
    cache[1] = 1; cache[2] = 1; 
    for(int i = 3 ; i <= N ; i++){
        cache[i] = cache[i-1] + cache[i-2];
    }
    cout << cache[N] << "\n";
}