#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct flower{
    int s_mon;
    int s_day;
    int e_mon;
    int e_day;
    
    int start_times(){
        return (s_mon*31 + s_day);
    }
    int end_times(){
        return (e_mon * 31 + e_day);
    }
};
flower flowers[100001];

bool cmp(flower a, flower b){
    if(a.s_mon < b.s_mon) return true;
    else if(a.s_mon > b.s_mon) return false;
    else{
        if(a.s_day <= b.s_day) return true;
        else return false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        
        cin >> flowers[i].s_mon >> flowers[i].s_day >> flowers[i].e_mon >> flowers[i].e_day;
        
    }
    sort(flowers, flowers+N, cmp);
    int res = 0;
    int b_idx = 0;
    int a_idx = 0;
    int cur_mon = 3; int cur_day = 1;
    int time = 0;
    int temp_mon = 0, temp_day = 0;
    while(1){
        temp_mon = 0; temp_day = 0; time = 0;
        for(int i = b_idx ; i < N ; i++){
            if(cur_mon* 31 + cur_day >= flowers[i].start_times()){
                if(time < flowers[i].end_times()){
                    time = flowers[i].end_times();
                    temp_mon = flowers[i].e_mon;
                    temp_day = flowers[i].e_day;
                    b_idx = i+1;
                }
            }
            else break;
        }
        res++;
        if(temp_mon == 0){
            res = 0;
            break;
        }
        if(temp_mon*31 + temp_day >= 12*31 +1) break;
        if(b_idx == N) {
            res = 0;
            break;
        }
        cur_mon = temp_mon;
        cur_day = temp_day;
    }
    cout << res << "\n";
}