#include <iostream>
#include <vector>

#define MAX 500001

using namespace std;

int n,m;

int parent[MAX];

void init(){
    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
    }
}
int Find(int a){
    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int a,b;
    init();
    int res = 0;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        if(Find(a) == Find(b) && res == 0){
            res = i+1;
        }
        Union(a,b);
    }
    cout << res << "\n";

}