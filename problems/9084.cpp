#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int N;
vector<int> v;
int result[10001];
int cal(int M){
    for(int i = 0 ; i < N ; i++){
        for(int j = v[i] ; j <= M ; j++){
            result[j] += result[j-v[i]];
        }
    }
    return result[M];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int T;
    
    cin >> T;
    while(T--){
        int M,coin;
        cin >> N;
        for(int i = 0 ; i < N ; i++){
            cin >> coin;
            v.push_back(coin);
        }
        cin >> M;
        memset(result, 0, sizeof(result));
        result[0] = 1;
        cout << cal(M) << "\n";
        v.clear();
    }
}