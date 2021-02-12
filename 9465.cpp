#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int testcase;
    int cache[2][100001];
    int arr[2][100001];

    cin >> testcase;
    int n;
    for(int i = 0 ; i < testcase ; i++){
        memset(arr, 0, sizeof(arr));
        cin >> n;
        for(int j = 0 ; j < 2 ; j++){
            for(int k = 0 ; k < n ; k++){
                cin >> arr[j][k];
            }
        }
        cache[0][0] = arr[0][0]; cache[1][1] = cache[0][0] + arr[1][1];
        cache[1][0] = arr[1][0]; cache[0][1] = cache[1][0] + arr[0][1];
        for(int j = 2 ; j < n ; j++){
            cache[0][j] = max(cache[1][j-1], cache[1][j-2]) + arr[0][j];
            cache[1][j] = max(cache[0][j-1], cache[0][j-2]) + arr[1][j];
        }
        cout << max(cache[1][n-1],cache[0][n-1]) << "\n";
    }
}