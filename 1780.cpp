#include <iostream>

using namespace std;

int map[2187][2187];
int oneCnt = 0;
int zeroCnt = 0;
int minusOneCnt = 0;

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
        divide(x, y, n/3); //first floor1
        divide(x + n/3, y, n/3); // first floor2
        divide(x + n/3*2, y, n/3); // first floor3
        divide(x, y + n/3, n/3);  //second floor1
        divide(x + n/3, y + n/3, n/3); //second floor2
        divide(x + n/3*2, y + n/3, n/3); //second floor2
        divide(x, y + n/3*2, n/3);  //third floor1
        divide(x + n/3, y + n/3*2, n/3);  //third floor2
        divide(x + n/3*2, y + n/3*2, n/3); //third floor3
    }
    else {
        if(map[y][x] == 0) zeroCnt++;
        else if(map[y][x] == 1) oneCnt++;
        else minusOneCnt++;
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
    cout << minusOneCnt << "\n" << zeroCnt << "\n" << oneCnt << "\n";
}