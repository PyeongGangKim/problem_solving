#include <iostream>
#include <stack>
#include <queue>
#include <cstring>

#define MAX 1004000

using namespace std;

bool check[MAX];
bool pelindrum(int num){
    stack<int> s;
    queue<int> q;
    while(num != 0){
        int insert = num%10;
        s.push(insert);
        q.push(insert);
        num /= 10;
    }

    while(!q.empty()){
        if(q.front() != s.top()) return false;
        q.pop();s.pop();
    }

    return true;
    

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    memset(check, false, sizeof(check));
    check[1] = true;
    for(int i = 2 ; i < MAX ; i++){
        for(int j = i*2 ; j < MAX ; j += i){
            check[j] = true;
        }
    }
    for(int i = N ; i < MAX ; i++){
        if(check[i] == false){
            if(pelindrum(i)){
                cout << i << "\n";
                break;
            }
        }
    }


}