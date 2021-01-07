#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int ability[20][20];
int n;
vector<int> check_num;
int check[20];
int result = 999999;
vector<int> team_start, team_link;


void cal(){
    int start = 0;
    int link = 0;
    for(int i = 0 ; i < n/2 ; i++){
        for(int j = 0 ; j < n/2 ; j++){
            start += ability[team_start[i]][team_start[j]];
            link += ability[team_link[i]][team_link[j]];
        }
    }
    team_start.clear();
    team_link.clear();
    int temp = abs(start - link);
    if(result > temp) result = temp;
}

void make_team(){
    for(int i = 0 ; i < n ; i++){
        if(check[i]) team_start.push_back(i);
        else team_link.push_back(i);
    }
}
void dfs(int t , int count){
    if(count == n/2){
        make_team();
        cal(); 
    }
    else{
        for(int i = t; i < n ; i++){
            if(!check[i]){
                check[i] = true;
                dfs(i+1 ,count+1);
                check[i] = false;
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> ability[i][j];
        }
    }
    dfs(0,0);

    cout << result << "\n";
}