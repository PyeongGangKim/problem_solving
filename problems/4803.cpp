#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
vector<int> tree[501];
int checkNode[501];
int checkEdge[501];

int countNode(int n){
    checkNode[n] = true;
    int cnt = 1;
    for(int i = 0 ; i < tree[n].size() ; i++){
        if(!checkNode[tree[n][i]]){
            cnt += countNode(tree[n][i]);
        }
    }
    return cnt;
}

int countEdge(int n){
    int cnt = tree[n].size();
    checkEdge[n] = true;
    for(int i = 0 ; i < tree[n].size() ; i++){
        if(!checkEdge[tree[n][i]]){
            cnt += countEdge(tree[n][i]);
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int node, edge, tempNode1, tempNode2;
    int treeCnt, cnt;
    cnt = 0;
    while(1){
        cin >> node >> edge;
        if(node == 0 && edge == 0) break;
        cnt++;
        treeCnt = 0;
        memset(checkNode, false, sizeof(checkNode));
        memset(checkEdge, false, sizeof(checkEdge));
        for(int i = 0 ; i < edge ; i++){
            cin >> tempNode1 >> tempNode2;
            tree[tempNode1].push_back(tempNode2);
            tree[tempNode2].push_back(tempNode1);
        }
        for(int i = 1 ; i <= node ; i++){
            if(!checkNode[i]){
                int edgeNum = countEdge(i);
                int nodeNum = countNode(i);
                if(nodeNum - 1 == edgeNum / 2) treeCnt++;
            }
        }
        for(int i = 1 ; i <= node ; i++){
            tree[i].clear();
        }
        cout << "Case " << cnt << ": "; 
        if(treeCnt == 0) cout << "No trees.\n";
        else if(treeCnt == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << treeCnt << " trees.\n";
    }

}