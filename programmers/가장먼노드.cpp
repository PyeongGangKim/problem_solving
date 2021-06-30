
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> node[20001];
bool check[20001];
int cnt[20001];
int maxNum = -1;

void bfs(){
    queue<pair<int, int> > q;
    q.push(make_pair(1,0));
    check[1] = true;
    while(!q.empty()){
        int n = q.front().first;
        int num = q.front().second;
        q.pop();
        for(int i = 0 ; i < node[n].size() ; i++){
            if(!check[node[n][i]]){
                q.push(make_pair(node[n][i], num + 1));
                check[node[n][i]] = true;
            }
        }

        maxNum = max(maxNum, num);
        cnt[num]++;

    }
}
int solution(int n, vector<vector<int> > edge) {
    int answer = 0;

    memset(cnt, 0, sizeof(cnt));
    memset(check, false, sizeof(check));

    for(int i = 0 ; i < edge.size() ; i++){
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    bfs();
    answer = cnt[maxNum];
    return answer;
}