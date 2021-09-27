#include <iostream>
#include <cstring>
#include <queue>

#define MAX 401

using namespace std;
int N, K;
int relation[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    memset(relation, 0, sizeof(relation));
    for(int i = 0 ; i < K ; i++){
        int f,s;
        cin >> f >> s;
        relation[f][s] = -1;
        relation[s][f] = 1;
    }
   
    for(int k = 1 ; k <= N ; k++){
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                if(relation[i][k] == -1 && relation[k][j] == -1){
                    relation[i][j] = -1;
                    relation[j][i] = 1;
                }
            }
        }
    }
        
    int tc;
    cin >> tc;
    for(int i = 0 ; i < tc ; i++){
        int n1, n2;
        cin >> n1 >> n2;
        cout << relation[n1][n2] << "\n";
    }
    
}