#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> nums;

int cal(){
    int start = 0;
    int end = n - 1;
    while(start != end){
        start++;
        nums.push_back(nums[start]);
        start++;
        end++;
    }
    return nums[start];
}
int main(){
 
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        nums.push_back(i);
    }
    cout << cal() << "\n";
}