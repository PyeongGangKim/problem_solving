#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
vector<int> student[501];
bool countS[501][501];
int check(){
    int result = 0;
    for(int i = 1 ; i <= N ; i++){
        bool isPossible = true;
        for(int j = 1 ; j <= N ; j++){
            if(i==j) continue;
            if(countS[i][j] == false) isPossible = false;
        }
        if(isPossible) result++;
    }
    return result;
}
void dfs(int i){
    //cout << i << " ";
    for(int j = 0 ; j < student[i].size() ; j++){
        countS[i][student[i][j]] = true;
        countS[student[i][j]][i] = true;
        dfs(student[i][j]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int shortH, tallH;
    for(int i = 0 ; i < M ; i++){
        cin >> shortH >> tallH;
        student[shortH].push_back(tallH);
    }
    memset(countS, false, sizeof(countS));
    for(int i = 1 ; i <= N ; i++){
        dfs(i);
        //cout << "\n";
    }
    cout << check() << "\n";
}