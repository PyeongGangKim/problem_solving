#include <iostream>

using namespace std;
int cacheZero[41];
int cacheOne[41];
void cal(int num){
    for(int i = 2 ; i <= num ; i++){
        cacheZero[i] = cacheZero[i-1] + cacheZero[i-2];
        cacheOne[i] = cacheOne[i-1] + cacheOne[i-2];
    }
    cout << cacheZero[num] << " " << cacheOne[num] << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cacheZero[0] = 1; cacheZero[1] = 0;
    cacheOne[0] = 0; cacheOne[1] = 1;
    int testCase;
    cin >> testCase;
    int num;

    for(int i = 0 ; i < testCase ; i++){
        cin >> num;
        cal(num);    
    }
}