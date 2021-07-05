#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long cache[101];

    cache[1] = 1;
    cache[2] = 1;
    cache[3] = 1;
    for(int i = 4 ; i <= 100 ; i++){
        cache[i] = cache[i-2] + cache[i-3];
    }
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int temp;
        cin >> temp;
        cout << cache[temp] << "\n";
    }
    
}