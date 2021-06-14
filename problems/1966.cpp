#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
queue<pair<int, int> > q;
int turn, N, target;

int print(){
    int cnt = 1;
    while(!q.empty()){
        if(pq.top() == q.front().second){
            if(target == q.front().first) break;
            pq.pop();
            q.pop();
            cnt++;
        }
        else{
            int first = q.front().first;
            int second = q.front().second;
            q.pop();
            q.push(make_pair(first,second));
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> turn;
    for(int i = 0 ; i < turn ; i++){
        cin >> N >> target;
        int temp;
        for(int j = 0 ; j < N ; j++){
            cin >> temp;
            pq.push(temp);
            q.push(make_pair(j,temp));
        }
        cout << print() << "\n";
        while(!q.empty()) q.pop();
        while(!pq.empty()) pq.pop();
    }

}