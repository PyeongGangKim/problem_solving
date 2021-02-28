#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int tree[1000001][2];

void postorder(int n){
    if(n == 0) return;

    postorder(tree[n][0]);
    postorder(tree[n][1]);

    cout << n << "\n";
}

void preorder(int root, int cur){
    if(cur > root ){
        if(tree[root][1] == 0){
            tree[root][1] = cur;
            return;
        }
        else{
            preorder(tree[root][1], cur);
        }
    }
    else{
        if(tree[root][0] == 0){
            tree[root][0] = cur;
            return;
        }
        else{
            preorder(tree[root][0], cur);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int root , n;
    cin >> root;
    memset(tree, 0, sizeof(tree));
    while(cin >> n){
        preorder(root,n);
    }
    postorder(root);
}