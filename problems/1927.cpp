#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > heap;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, temp;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        if(temp != 0) heap.push(temp);
        if(temp == 0){
            if(!heap.empty()){
                cout << heap.top() << "\n";
                heap.pop();
            }
            else{
                cout << "0\n" ;
            }
        }
    }
}
