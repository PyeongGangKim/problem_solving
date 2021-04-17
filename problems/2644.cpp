#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
vector<int> graph[101];
int check[101];
int start,targetN, N;

int BFS(){
    queue<pair<int, int> > q;
    q.push(make_pair(start,0));
    while(!q.empty()){
        int curNode = q.front().first; 
        int curChon = q.front().second;
        check[curNode] = true;
        q.pop();
        if(curNode == targetN) return curChon;
        for(int i = 0 ; i < graph[curNode].size() ; i++){
            int nextNode = graph[curNode][i];
            if(!check[nextNode]){
                q.push(make_pair(nextNode, curChon + 1));
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    cin >> start >> targetN;
    int edgeNum;
    cin >> edgeNum;
    for(int i = 0 ; i < edgeNum ; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    memset(check, false, sizeof(check));
    cout << BFS() << "\n";
}