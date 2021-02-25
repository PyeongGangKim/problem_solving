#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num;
    cin >> num;
    int data;
    for(int i = 0 ; i < num * num ; i++){
        cin >> data;
        if(pq.size() < num){
            pq.push(data);
        }
        else{
            if(pq.top() < data){
                pq.pop();
                pq.push(data);
            }
        }
     
    }
    cout << pq.top();
}