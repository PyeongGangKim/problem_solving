#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> max_heap;
priority_queue<int ,vector<int>, greater<int> > min_heap;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    int temp;
    for(int i = 0 ; i < num ; i++){
        cin >> temp;
        if(max_heap.size() == min_heap.size()){
            max_heap.push(temp);
        }
        else{
            min_heap.push(temp);
        }
        if(max_heap.size() != 0 && min_heap.size() != 0 && max_heap.top() > min_heap.top()){
            int max_temp = max_heap.top();
            int min_temp = min_heap.top();
            max_heap.pop();
            min_heap.pop();
            max_heap.push(min_temp);
            min_heap.push(max_temp);
        }
        cout << max_heap.top() << "\n";
    }
}