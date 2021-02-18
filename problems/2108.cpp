#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int fre_num[8001] = {0,};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int num;
    cin >> num;
    int temp;
    double sum = 0;
    vector<int> nums;
    for(int i = 0 ; i < num ; i++){
        cin >> temp;
        sum += temp;
        nums.push_back(temp);
        if(temp < 0){
            int minus_temp = 4000 - temp;
            fre_num[minus_temp]++;
        }
        else{
            fre_num[temp]++;
        }
    }
    double mean = (double)sum/num;
    sort(nums.begin(),nums.end());
    int mid = nums.at((num/2));
    int range = nums.back() - nums.front();
    int max = 0;
    int max_num;
    vector<int> fre_v;
    for(int i = 0 ; i < 8001 ; i++){
        if(max <= fre_num[i]){
            if (i > 4000) max_num = 4000 - i;
            else max_num = i;
            if(max == fre_num[i]){
                fre_v.push_back(max_num);
                continue;
            }
            max = fre_num[i];
            fre_v.clear();
            fre_v.push_back(max_num);
        }
    }
    sort(fre_v.begin(),fre_v.end());
    cout << round(mean) << "\n";
    cout << mid << "\n";
    if(fre_v.size() > 1){
        cout << fre_v.at(1) << "\n";
    }
    else{
        cout << fre_v.at(0) << "\n";
    }
    cout << range << "\n";
}