#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int N;
char board[51][51];

int res = 0;

void check(){
    
    for(int r = 0 ; r < N ; r++){
        char color = board[r][0];
        int cnt = 1;
        for(int c = 1 ; c < N ; c++){
            if(color == board[r][c]) cnt++;
            else{
                res = max(res,cnt);
                color = board[r][c];
                cnt = 1;
            }
        }
        res = max(res,cnt);
    }

    for(int c = 0 ; c < N ; c++){
        char color = board[0][c];
        int cnt = 1;
        for(int r = 1 ; r < N ; r++){
            if(color == board[r][c]) cnt++;
            else{
                res = max(res,cnt);
                color = board[r][c];
                cnt = 1;
            }
        }
        res = max(res,cnt);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        string temp;
        cin >> temp;
        for(int j = 0 ; j < N ; j++){
            board[i][j] = temp[j];
        }
    }

    for(int r = 0 ; r < N ; r++){
        for(int c = 0 ; c < N - 1 ; c++){
            swap(board[r][c], board[r][c+1]);
            check();
            swap(board[r][c], board[r][c+1]);
        }
    }

    for(int c = 0 ; c < N ; c++){
        for(int r = 0 ; r < N - 1 ; r++){
            swap(board[r][c], board[r+1][c]);
            check();
            swap(board[r][c], board[r+1][c]);
        }
    }

    cout << res << "\n";
}