#include <iostream>

using namespace std;

int map[128][128];
int blueCnt = 0;
int whiteCnt = 0;

bool check(int x, int y, int n){
    int temp = map[y][x];
    for(int i = y ; i < y+n ; i++){
        for(int j = x ; j < x+n ; j++){
            if(map[i][j] != temp) return false;
        }
    }
    return true;
}
void divide(int x, int y, int n){
    if(!check(x, y, n)){
        divide(x, y, n/2); //left
        divide(x + n/2, y, n/2); // right
        divide(x, y + n/2, n/2);  //low
        divide(x + n/2, y + n/2, n/2); //low
    }
    else {
        map[y][x] ? blueCnt++ : whiteCnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < num ; j++){
            cin >> map[i][j];
        }
    }
    divide(0, 0, num);
    cout << whiteCnt << "\n" << blueCnt << "\n";
}