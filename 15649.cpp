#include <iostream>
#include <vector>

using namespace std;

int N,M;
bool check[9]= {false,};
vector<int> result;

void dfs(int count){
    if(M == count){
        for(int i = 0 ; i < M ; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    else{
        for(int i = 1 ; i <= N ; i++){
            if(!check[i]){
                result.push_back(i);
                check[i] = true;
                dfs(count + 1);
                check[i] = false;
                result.pop_back();
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin >> N >> M;

    dfs(0);
}