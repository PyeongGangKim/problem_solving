#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int maxChicken;
vector<pair<int, int> > home;
vector<pair<int, int> > chickenHouse;
vector<int> selectedCHouse;
int selectedChicken[13] = {false, };
int dist[100];
int minDist = 987654321;

void calDist(){
    for(int i = 0 ; i < maxChicken ; i++){
        int temp = selectedCHouse[i]; 
        
        for(int j = 0 ; j < home.size() ; j++){
            int tempDist = abs(chickenHouse[temp].first - home[j].first) + abs(chickenHouse[temp].second - home[j].second);
            if(dist[j] == -1 || dist[j] > tempDist) dist[j] = tempDist; 
            
        }
    }
    int sumDist = 0;
    for(int i = 0 ; i < home.size() ; i++){
        sumDist += dist[i];
    }
    minDist = min(minDist, sumDist);
}

void combination(int num, int cnt){
    if(cnt == maxChicken){
        calDist();
        memset(dist,-1,sizeof(dist));
    }
    else{
        for(int i = num ; i < chickenHouse.size() ; i++){
            if(!selectedChicken[i]){
                selectedChicken[i] = true;
                selectedCHouse.push_back(i);
                combination(i, cnt+1);
                selectedCHouse.pop_back();
                selectedChicken[i] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> maxChicken;
    int temp;
    int count = 0;
    memset(dist, -1, sizeof(dist));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> temp;
            if(temp == 1) home.push_back(make_pair(i,j));
            else if(temp == 2) chickenHouse.push_back(make_pair(i,j));
        }
    }
    combination(0,0);
    cout << minDist << "\n";
}