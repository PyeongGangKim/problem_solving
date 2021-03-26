#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
ll stairs[301];
ll cache[301];
int num;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    memset(cache, -1, sizeof(cache));
    cin >> num;

    for(int i = 1 ; i <= num ; i++){
        cin >> stairs[i];
    }
    cache[1] = stairs[1];
    cache[2] = stairs[1] + stairs[2];
    cache[3] = max(cache[1] + stairs[3], stairs[2]+ stairs[3]);
    for(int i = 4 ; i <= num ; i++){
        cache[i] = max(cache[i-2] + stairs[i], stairs[i] + stairs[i-1] + cache[i-3]);
    }
    cout << cache[num] << "\n";
}