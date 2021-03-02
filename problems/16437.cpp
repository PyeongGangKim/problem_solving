#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
char WorS[123457];
vector<long long> tree[123457];
long long animalNumbers[123457];
long long dfs(int n){
    long long cnt = 0;
    for(int i = 0 ; i < tree[n].size() ; i++){
            cnt += dfs(tree[n][i]);
    }
    if(WorS[n] == 'W'){
        cnt = cnt - animalNumbers[n];
        if(cnt < 0) return 0;
        else return cnt;
    }
    else return cnt + animalNumbers[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    long long nodeNum;
    cin >> nodeNum;
    char animal;
    long long numbers;
    long long node;
    for(long long i = 2 ; i <= nodeNum ; i++){
        cin >> animal >> numbers >> node;
        WorS[i] = animal; animalNumbers[i] = numbers;
        tree[node].push_back(i); 
    }
    WorS[1] = 'S'; animalNumbers[1] = 0;
    cout << dfs(1) << "\n";
}


