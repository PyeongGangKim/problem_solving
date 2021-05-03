#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int parent[1000001];
int n,m;

int find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}
void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        parent[x] = y;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0 ; i <= n ; i++){
        parent[i] = i;
    }
    int opt, num1, num2;
    for(int i = 0 ; i < m ; i++){
        cin >> opt >> num1 >> num2;
        if(opt == 0){
            uni(num1, num2);
        }
        if(opt == 1){
            if(find(num1) == find(num2) ) cout << "YES" << "\n";
            else cout << "NO\n";
        }
    }

}