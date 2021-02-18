#include <iostream>

using namespace std;

int badCombi[201][201] = {0, };
int check[201] = {0, };
int badNum;
int iceNum;

int goodNum = 0;


bool combiCheck(){
    int cnt = 0;
    for(int i = 1 ; i <= iceNum ; i++){
        int num;
        if(check[i] == 1) {
            num = i; 
            cnt++;
            
        }
        else continue;
        if(cnt == 3) break;
        for(int j = num + 1 ; j <= iceNum ; j++){
            if(check[j] &&badCombi[num][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void combination(int n , int cnt){
    if(cnt == 3){
        if(combiCheck()) goodNum++;
    }
    else{
        for(int i = n ; i <= iceNum ; i++){
            if(check[i] == 0){
                check[i] = 1;
                //cout << i << "\n";
                combination(i , cnt+1);
                check[i] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> iceNum >> badNum;
    int tempX, tempY;
    for(int i = 0 ; i < badNum ; i++){
        cin >> tempY >> tempX;
        if(tempY > tempX) badCombi[tempX][tempY] = 1;
        else badCombi[tempY][tempX] = 1;
    }
    combination(1,0);
    cout << goodNum << "\n";
}