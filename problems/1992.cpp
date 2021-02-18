#include <iostream>
#include <string>

using namespace std;

int map[64][64];



bool check(int x, int y, int n){
    int temp = map[y][x];
    for(int i = y ; i < y+n ; i++){
        for(int j = x ; j < x+n ; j++){
            if(map[i][j] != temp) return false;
        }
    }
    return true;
}

string divide(int x, int y, int n){
    string temp = "";
    if(!check(x, y, n)){
        temp += "(";
        temp += divide(x, y, n/2); //left
        temp += divide(x + n/2, y, n/2); // right
        temp += divide(x, y + n/2, n/2);  //low
        temp += divide(x + n/2, y + n/2, n/2); //cross
        temp += ")";
        return temp;
    }
    else return temp += to_string(map[y][x]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num;
    string temp;
    cin >> num;
    for(int i = 0 ; i < num ; i++){
        cin >> temp;
        for(int j = 0 ; j < num ; j++){
            map[i][j] = temp[j] - '0';
        }
    }
    
    cout << divide(0, 0, num) << "\n";
    
}