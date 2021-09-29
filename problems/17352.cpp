#include <iostream>

#define MAX 300001

using namespace std;

int parent[MAX];

int N;

int Find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}
void init(){
    for(int i = 1 ; i <= N ; i++){
        parent[i]= i;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    init();
    for(int i = 0 ; i < N - 2; i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }
    for(int i = 1 ; i <= N ; i++){
        if(Find(i) != 1){
            cout << 1 << " " << i << "\n";
            break;
        }
    }
}