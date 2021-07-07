#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int cache[41];
    cache[0] = 1;
    cache[1] = 1; cache[2] = 2;
    int N, M;
    cin >> N >> M;
    for(int i = 3 ; i <= N ; i++){
        cache[i] = cache[i-1] + cache[i-2];
    }
    int temp;
    int result = 1;
    int prev = 0;
    while(M--){
        cin >> temp;
        result *= cache[temp - prev - 1];
        prev = temp;
    }
    result *= cache[N - prev];
    cout << result << "\n";
}