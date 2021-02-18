#include <iostream>
#include <vector>

using namespace std;

bool check[20] = {false, };
int nums[20];
bool numCheck[2000000] = {false, };

int numSize;
int maxNum = -1;

void cal(){
    int temp = 0;
    for(int i = 0 ; i < numSize ; i++){
        if(check[i]) temp += nums[i];
    }
    numCheck[temp] = true;
    maxNum = max(maxNum, temp);
}

void combination(int n, int cnt, int maxCnt){
    if(cnt == maxCnt){
        cal();
    }
    else{
        for(int i = n ; i < numSize ; i++){
            if(!check[i]){
                check[i] = true;
                combination(i, cnt + 1, maxCnt);
                check[i] = false;
            }
        }
    }
}
int checkMinNum(){
    for(int i = 1 ; i <= maxNum ; i++){
        if(!numCheck[i]) return i;
    }
    return maxNum + 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> numSize;
    for(int i = 0 ; i < numSize ; i++){
        cin >> nums[i];
    }
    for(int i = 1 ; i <= numSize ; i++){
        combination(0, 0, i);
    }

    cout << checkMinNum() << "\n";
    
}
