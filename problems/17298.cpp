#include <iostream>
#include <vector>

using namespace std;

int nums[1000001];
int input[1000001];
vector<int> v;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int temp;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        input[i] = temp;
    }
    for(int i = N - 1 ; i >= 0 ; i--){
        if(i == N-1){
            nums[i] = -1;
            v.push_back(input[i]);
        }
        while(v.size()){
            if(v.back() > input[i]){
                nums[i] = v.back();
                break;
            }
            else v.pop_back();
        }
        if(v.size() == 0){
            nums[i] = -1;
        }
        v.push_back(input[i]);
    }
    for(int i = 0 ; i < N ; i++){
        cout << nums[i] << " ";
    }
    cout << "\n";
}