#include <iostream>
#include <vector>

using namespace std;
typedef struct _node{
    char left;
    char right;
}node;

node tree[27];

void preorder(char n){
    if(n == '.') return;
    cout << n;
    preorder(tree[n].left);
    preorder(tree[n].right);
}
void inorder(char n){
    if(n == '.') return;
    inorder(tree[n].left);
    cout << n;
    inorder(tree[n].right);
}
void postorder(char n){
    if(n == '.') return;
    postorder(tree[n].left);
    postorder(tree[n].right);
    cout << n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int num;
    cin >> num;
    char parent, leftChild, rightChild;
    for(int i = 0 ; i < num ; i++){
        cin >> parent >> leftChild >> rightChild;
        tree[parent].left = leftChild;
        tree[parent].right = rightChild;
    }  
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";
}