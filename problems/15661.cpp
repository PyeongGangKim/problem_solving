#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>teamStart;
vector<int>teamLink;
int check[21] = {false, };
int N;
int ability[21][21];
int minScore = 987654321;

void makeTeam(){
    for(int i = 0 ; i < N ; i++){
        if(check[i]) teamStart.push_back(i);
        else teamLink.push_back(i);
    }
}

int calAbility(vector<int> &team){
    int score = 0 ;
    for(int i = 0 ; i < team.size() ; i++){
        for(int j = 0 ; j < team.size() ; j++){
            if(i == j) continue;
            score += ability[team[i]][team[j]];
        }
    }
    return score;
}

void dividePlayer(int idx, int max, int n){
    if(n == max){
        teamStart.clear();
        teamLink.clear();
        makeTeam();
        int startScore = calAbility(teamStart);
        int linkScore = calAbility(teamLink);
        minScore = min(minScore, abs(startScore - linkScore));
    }
    else{
        for(int i = idx ; i < N ; i++){
            if(check[i]) continue;
            check[i] = true;
            dividePlayer(i, max, n+1);
            check[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> ability[i][j]; 
        }
    }
    for(int i = 2 ; i < N/2 + 1 ; i++){
        dividePlayer(0,N/2,0);
        
    }

    cout << minScore << "\n";
}