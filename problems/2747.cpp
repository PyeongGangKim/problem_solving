#include <iostream>

using namespace std;

int cache[47];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int N ; 
    cin >> N;
    cache[0] = 0;
    cache[1] = 1;
    for(int i = 2 ; i <= N ; i++){
        cache[i] = cache[i-1] + cache[i-2];
    }

    cout << cache[N] << "\n";
}