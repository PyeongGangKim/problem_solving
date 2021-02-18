#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pathCost[11][11];
int pathNum;
vector<int> canPath;
int INF = 987654321;

bool checkNum[11] = {false, };
int minPathCost = 987654321;

int checkPathCost(){
    int tempCost = 0;
    for(int i = 0 ; i < pathNum - 1 ; i++){
        if(pathCost[canPath[i]][canPath[i+1]] == 0) return INF;
        tempCost += pathCost[canPath[i]][canPath[i+1]];
    }
    if(pathCost[canPath[pathNum - 1]][canPath[0]] == 0) return INF;
    return tempCost + pathCost[canPath[pathNum - 1]][canPath[0]];
}

void makePath(){
    if(canPath.size() == pathNum){
        minPathCost = min(minPathCost, checkPathCost());
    }
    else{
        for(int i = 0 ; i < pathNum ; i++){
            if(!checkNum[i]){
                canPath.push_back(i);
                checkNum[i] = true;
                makePath();
                checkNum[i] = false;
                canPath.pop_back();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> pathNum;
    for(int i = 0 ; i < pathNum ; i++){
        for(int j = 0 ; j < pathNum ; j++){
            cin >> pathCost[i][j];
        }
    }
    makePath();
    cout << minPathCost << "\n";
}