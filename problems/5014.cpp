#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int check[1000001];
int start,targetN, N;
int button[2];

int BFS(){
    queue<pair<int, int> > q;
    q.push(make_pair(start,0));
    check[start] = true;
    while(!q.empty()){
        int curNode = q.front().first; 
        int curButtonNum = q.front().second;
        
        q.pop();
        if(curNode == targetN) return curButtonNum;
        for(int i = 0 ; i < 2 ; i++){
            int nextNode = button[i] + curNode;
            if(!check[nextNode] && nextNode <= N && 0 < nextNode){
                check[nextNode] = true;
                q.push(make_pair(nextNode, curButtonNum + 1));
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> start >> targetN >> button[0] >> button[1];
    button[1] = button[1] * -1;

    memset(check, false, sizeof(check));
    int result = BFS();
    if(result == -1)cout << "use the stairs" << "\n";
    else cout << result << "\n";
}