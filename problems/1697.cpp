#include <iostream>
#include <queue>

using namespace std;

int N, K;

typedef struct Node{
    int location;
    int time;
}node;

queue<node> q;

bool check[100001] = {false, };

int branch[3] = {1, -1, 2};

int finalTime;

void bfs(){
    node temp;
    node newNode;
    int location;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i = 0 ; i < 3 ; i++){
            if(i == 2) location = temp.location * branch[i];
            else location = temp.location + branch[i];
            if(location >= 0 && location <= 100000 && !check[location]){
                if(location == K) {
                    finalTime = temp.time + 1;
                    return;
                }
                check[location] = true;
                newNode.location = location;
                newNode.time = temp.time + 1;
                q.push(newNode);

            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> K;
    node temp = {N, 0};
    check[N] = true;
    q.push(temp);
    bfs();
    cout << finalTime << "\n";
}