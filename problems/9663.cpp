#include <iostream>
#include <cstdlib>

using namespace std;
int col[15];
int N; 
int result = 0;
bool check(int level){
    for(int i = 0 ; i < level ; i++){
        if(col[i] == col[level] || abs(col[i] - col[level]) == level - i) return false;
    }
    return true;
}
void cal(int x){
    if(x==N){
        result++;
    }
    else{
        for(int i = 0 ; i < N ; i++){
            col[x] = i;
            if(check(x)){
                cal(x+1);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    
    cin >> N;
    cal(0);
    cout << result << "\n";
}