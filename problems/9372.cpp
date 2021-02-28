#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int testcase;
    cin >> testcase;
    int N, M, n, m;
    for(int i = 0 ; i < testcase ; i++){
        cin >> N >> M;
        for(int j = 0 ; j < M; j++){
            cin >> n >> m;
        }
        cout << N-1 << "\n";
    }
}