#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string input;
    deque<char> dq;

    int N, K;
    cin >> N >> K;
    cin >> input;

    for(int i = 0 ; i < N ; i++){
        while(K && !dq.empty() && dq.back() < input[i]){
            K--;
            dq.pop_back();
        }
        dq.push_back(input[i]);
    }
    cout << dq.size() << "\n";
    for(int i = 0 ; i < dq.size()-K ; i++){
        cout << dq[i];
    }
    cout << "\n";

}