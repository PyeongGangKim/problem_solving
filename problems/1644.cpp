#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
bool num[4000001];
vector <int> v;// 소수 넣는 vector
int target;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> target;
    memset(num, false, sizeof(num));
    for(int i = 2 ; i <= target ; i++){
        for(int j = i*2 ; j <= target ; j = j+i){
            num[j] = true;
        }
    }
    for(int i = 2 ; i <= target ; i++){
        if(!num[i]) v.push_back(i);
    }
    int start = 0;
    int end = 0;
    int result = 0;
    int maxSize = v.size();
    if(maxSize != 0){
        int sum = v[start];
        while(end <= maxSize && start <= end){
            if(sum >= target){
                if(sum == target) result++;
                sum -= v[start];
                start++;
            }
            else{
                end++;
                //if(end > maxSize) break;
                sum += v[end];

            }
        }
    }
    cout << result << "\n";
}