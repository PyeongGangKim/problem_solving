#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int cache[1001];
int box[1001];
int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> box[i];
    }
    int maxNum = -1;
    for(int i = 0 ; i < N ; i++){
        cache[i] = 1;
        for(int j = 0 ; j < i ; j++){
            if(box[j] < box[i]){
                cache[i] = max(cache[i], cache[j] + 1);
            }
        }
        maxNum = max(maxNum, cache[i]);
    }
    cout << maxNum << "\n";
}