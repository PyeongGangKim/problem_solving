#include <iostream>
#include <vector>

using namespace std;

int nums[500001];
vector<pair<int, int> > v;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int temp;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        if(i==0){
            v.push_back(make_pair(temp,i+1));
            nums[i] = 0;
            continue;
        }
        while(v.size()){
            if(temp < v.back().first){
                nums[i] = v.back().second;
                break;
            }
            else v.pop_back();
        }
        if(v.size() == 0){
            nums[i] = 0;
        }
        v.push_back(make_pair(temp, i+1));

    }
    for(int i = 0 ; i < N ; i++){
        cout << nums[i] << " ";
    }
    cout << "\n";
}