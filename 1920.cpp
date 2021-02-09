#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> check;
int N, M;

bool checkNum(int n, int s ,int e){
    if(e < s){
        return false;
    }
    else{
        int m = (s + e) / 2; 
        if(check[m]== n) return true;
        else if(check[m] < n) return checkNum(n, m+1, e);
        else return checkNum(n, s , m-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin >> N;

    int temp;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        check.push_back(temp);
    }
    sort(check.begin(),check.end());
    cin >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> temp;
        if(checkNum(temp, 0, N -1)) cout << "1" << "\n";
        else cout << "0" << "\n";
    }

}