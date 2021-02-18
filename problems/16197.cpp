#include <iostream>
#include <queue>

using namespace std;

typedef struct Node{
    int x;
    int y;
    int num;
}node;
queue<pair<node,node> > q;

int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};

int map[21][21];
int X,Y; 

int BFS(){
    while(!q.empty()){
        node tempNode1, tempNode2;
        node newNode1, newNode2;
        tempNode1 = q.front().first; tempNode2 = q.front().second;
        q.pop();
        if(tempNode1.num >= 10) break;
        for(int i = 0 ; i < 4 ; i++){
            int nX1 = tempNode1.x + xCheck[i]; int nX2 = tempNode2.x + xCheck[i];
            int nY1 = tempNode1.y + yCheck[i]; int nY2 = tempNode2.y + yCheck[i];
            if((nY1 < 0 || nX1 < 0 || nY1 >= Y || nX1 >= X) && (nY2 < 0 || nX2 < 0 || nY2 >= Y || nX2 >= X)) continue;
            else if(!(nY1 < 0 || nX1 < 0 || nY1 >= Y || nX1 >= X) && !(nY2 < 0 || nX2 < 0 || nY2 >= Y || nX2 >= X)){
                if(map[nY1][nX1] == 2 && map[nY2][nX2] == 2) continue;
                else if(map[nY1][nX1] == 2){
                    newNode1.x = tempNode1.x; newNode1.y = tempNode1.y; newNode1.num = tempNode1.num + 1;
                    newNode2.x = nX2; newNode2.y = nY2; newNode2.num = tempNode2.num + 1;
                }
                else if(map[nY2][nX2] == 2){
                    newNode1.x = nX1; newNode1.y = nY1; newNode1.num = tempNode1.num + 1;
                    newNode2.x = tempNode2.x; newNode2.y = tempNode2.y; newNode2.num = tempNode2.num + 1;
                }
                else{
                    newNode1.x = nX1; newNode1.y = nY1; newNode1.num = tempNode1.num + 1;
                    newNode2.x = nX2; newNode2.y = nY2; newNode2.num = tempNode2.num + 1;
                }
                q.push(make_pair(newNode1, newNode2));
            }
            else return tempNode1.num + 1;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> Y >> X;
    char temp;
    node newNode1, newNode2;
    int num = 0 ;

    for(int i = 0 ; i < Y ; i++){
        for(int j = 0 ; j < X ; j++){
            cin >> temp;
            if(temp == '.') map[i][j] = 0;
            else if(temp == '#') map[i][j] = 2;
            else {
                map[i][j] = 0;
                if(num == 0){
                    newNode1.x = j;
                    newNode1.y = i;
                    newNode1.num = 0;
                    num++;
                }
                if(num == 1){
                    newNode2.x = j;
                    newNode2.y = i;
                    newNode2.num = 0;
                }
            }
        }
    }
    q.push(make_pair(newNode1,newNode2));
    cout << BFS() << "\n";
}