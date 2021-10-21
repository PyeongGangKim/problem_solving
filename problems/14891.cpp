#include <iostream>
#include <string>

using namespace std;

int front[5];
int back[5];
int topni[5][8];
int res[5];
int val[4] = {1,2,4,8};

void init(){
    for(int i = 1 ; i < 5 ; i++){
        front[i] = 7;
    }
    for(int i = 1 ; i < 5 ; i++){
        back[i] = 3;
    }
}
void move_front(int n, int dir){
    bool can_move = false;
    if(n >= 2 && topni[n][front[n]] != topni[n-1][back[n-1]]) can_move = true;
    
    if(dir == 1){
        front[n] = (front[n] - 1 <= 0) ? 8 : front[n] - 1;  // 시계방향인경우
    }
    else{
        front[n] = (front[n] + 1 > 8) ? 1 : front[n] + 1;  // 반시계방향인경우
    }
    if(can_move){
        if(dir == 1){ // 시계방향인 경우
            back[n-1] = (back[n-1] + 1 > 8) ? 1 : back[n-1] + 1;
        }
        else{
            back[n-1] = (back[n-1] - 1 <= 0) ? 8 : back[n-1] - 1;
        }
        move_front(n-1,dir*-1);

    }

}
void move_back(int n, int dir){
    bool can_move = false;
    if(n <= 3 && topni[n][back[n]] != topni[n+1][front[n+1]]) can_move = true;
    
    if(dir == 1){
        back[n] = (back[n] - 1 <= 0) ? 8 : back[n] - 1;  // 시계방향인경우
    }
    else{
        back[n] = (back[n] + 1 > 8) ? 1 : back[n] + 1;  // 반시계방향인경우
        
    }
    if(can_move){
        if(dir == 1){ // 시계방향인 경우
            front[n+1] = (front[n+1] + 1 > 8) ? 1 : front[n+1] + 1;
        }
        else{
            front[n+1] = (front[n+1] - 1 <= 0) ? 8 : front[n+1] - 1; 
        }
        move_back(n+1,dir*-1);
        
    }

}
void move(int n, int dir){
    //움직 일수 있는 부분 체크
    bool front_move = false;
    bool back_move = false;
    if(n >= 2 && topni[n][front[n]] != topni[n-1][back[n-1]]) front_move = true;
    if(n <= 3 && topni[n][back[n]] != topni[n+1][front[n+1]]) back_move = true;
    
    if(dir == 1){
        front[n] = (front[n] - 1 <= 0) ? 8 : front[n] - 1;  // 시계방향인경우
        back[n] = (back[n] - 1 <= 0) ? 8 : back[n] - 1;
        
    } 
    else{
        front[n] = (front[n] + 1 > 8) ? 1 : front[n] + 1;  // 반시계방향인경우
        back[n] = (back[n] + 1 > 8) ? 1 : back[n] + 1;
    }
    if(front_move){
        if(dir == 1){ // 시계방향인 경우
            back[n-1] = (back[n-1] + 1 > 8) ? 1 : back[n-1] + 1;
        }
        else{
            back[n-1] = (back[n-1] - 1 <= 0) ? 8 : back[n-1] - 1;
        }
        move_front(n-1,dir*-1);
        
    }
    if(back_move){
        if(dir == 1){ // 시계방향인 경우
            front[n+1] = (front[n+1] + 1 > 8) ? 1 : front[n+1] + 1;
        }
        else{
            front[n+1] = (front[n+1] - 1 <= 0) ? 8 : front[n+1] - 1; 
        }
        move_back(n+1,dir*-1);
    
    }
    
}
int sum(){
    for(int i = 1 ; i < 5 ; i++){
        int temp;
        if(back[i] - 2 <= 0){
            temp = back[i] - 2 + 8;
        
        }
        else temp = back[i] - 2;
        
        if(topni[i][temp] == 1) res[i] = 1;
    }
    int sum_res = 0;
    for(int i = 0 ; i < 4 ; i++){
        
        sum_res += res[i+1] * val[i];
    }
    return sum_res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    for(int i = 1 ; i <= 4 ; i ++){
        string str;
        cin >> str;
        for(int j = 1 ; j <= 8 ; j++){
            topni[i][j] = str[j-1] - '0';
        }
    }
    int K;
    cin >> K;
    for(int i = 0 ; i < K ; i++){
        int num, dir;
        cin >> num >> dir;
        move(num, dir);
    }
    cout<< sum() << "\n";
}