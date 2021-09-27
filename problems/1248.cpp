#include <iostream>
#include <vector>
#include <string>

#define MAX 10

using namespace std;

char cmp[MAX][MAX];
int Select[MAX];

int N;


bool isRight(int cnt){
    for(int i = 0 ; i < cnt ; i++){
        int temp = 0;
        for(int j = i ; j < cnt ; j++){
            temp += Select[j];
            if(cmp[i][j] == '-' && temp >= 0) return false;
            else if(cmp[i][j] == '+' && temp <= 0) return false;
            else if(cmp[i][j] == '0' && temp != 0) return false;
        }
    }
    return true;
}

void dfs(int cnt){
    if(cnt == N){
        if(isRight(cnt)){
            for(int i = 0 ; i < N ; i++){
                cout << Select[i] << " ";
            }
            cout << "\n";
            exit(0);
        }
    }
    else{
        for(int i = -10 ; i <= 10 ; i++){
            Select[cnt] = i;
            if(isRight(cnt + 1)) dfs(cnt + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = i ; j < N ; j++){
            cin >> cmp[i][j];
        }
    }
    dfs(0);

}