#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second > b.second) return true;
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> pq;
    
    int time = 0;
    
    int cnt = 0;
    int i = 0;
    int start = -1;
    while(i < jobs.size()){
        for(int i = 0 ; i < jobs.size() ; i++){
            if(jobs[i][0] > start && jobs[i][0] <= time){
                pq.push(make_pair(jobs[i][0], jobs[i][1]));
            }
        }
        if(!pq.empty()){
            cout <<  start << " " << time << " " << pq.top().first << " " << pq.top().second << "\n";
            start = time;
            time += pq.top().second;
            answer += (time - pq.top().first);
            pq.pop();
            i++;
        }
        else{
            time++;
        }
    }
    
    return answer/jobs.size();
}