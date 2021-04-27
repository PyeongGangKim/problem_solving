#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, less<int> > heap;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, temp;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        heap.push(temp);
        if(temp == 0){
            cout << heap.top() << "\n";
            heap.pop();
        }
    }
}
