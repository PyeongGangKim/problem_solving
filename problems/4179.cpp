#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

char map[1001][1001];
bool visited[1001][1001] ={false,};
int R,C;

typedef struct Node{
    int x;
    int y;
}node;
node start;
int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};

queue<node> fire;
queue<node> person;

int maxTime = 0 ;

int bfs(){

    int cnt = 0;
    int x, y;
    node temp, newNode;
    int fireSize, personSize; 
    while(!person.empty()){
        fireSize = fire.size();
        for(int i = 0 ; i < fireSize ; i++){
            temp = fire.front();
            fire.pop();
            for(int j = 0 ; j < 4 ; j++){
                x = temp.x + xCheck[j];
                y = temp.y + yCheck[j];
                if(x >= 0 && y >= 0 && x < C && y < R){
                    if(map[x][y] == '.' || map[x][y] == 'J'){
                        map[x][y] = 'F';
                        newNode.x = x;
                        newNode.y = y;
                        fire.push(newNode);
                    }
                }
            }
        }
        personSize = person.size();
        for(int i = 0 ; i < personSize ; i++){
            temp = person.front();
            person.pop();
            if(temp.x == 0 || temp.x == C -1 || temp.y == 0 || temp.y == R - 1) return cnt + 1;
            for(int j = 0 ; j < 4 ; j++){
                x = temp.x + xCheck[j];
                y = temp.y + yCheck[j];
                if(x >= 0 && y >= 0 && x < C && y < R && !visited[x][y]){
                    if(map[x][y] == '.' ){
                        visited[x][y] = true;
                        newNode.x = x;
                        newNode.y = y;
                        person.push(newNode);
                    }
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> R >> C;
    string str;
    node temp;
    
    for(int i = 0 ; i < R ; i++){
        cin >> str;
        for(int j = 0 ; j < C ; j++){
            if(str[j] == '#') map[i][j] = '#';
            else if(str[j] == '.') map[i][j] = '.';
            else if(str[j] == 'F'){
                map[i][j] = 'F';
                temp.x = i;
                temp.y = j;
                fire.push(temp);
            }
            else if(str[j]=='J'){
                map[i][j] = 'J';
                temp.x = i;
                temp.y = j;
                person.push(temp);
            }
        }
    }
    maxTime = bfs();
    if(maxTime != -1) cout << maxTime << "\n";
    else cout << "IMPOSSIBLE" << "\n";
}