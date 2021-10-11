#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct flower{
    int s;
    int e;
    
    
};
flower flowers[100001];

bool cmp(flower a, flower b){
    if(a.s < b.s) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int s_mon,s_day,e_mon,e_day;
        cin >> s_mon >> s_day >> e_mon >> e_day;
        if(s_mon * 100 + s_day < 301){
            s_mon = 3; s_day = 1;
        }
        if(e_mon*100 + e_day > 1130){
            e_mon = 12; e_day = 1;
        }

        flowers[i].s = s_mon*100 + s_day;
        flowers[i].e = e_mon * 100 + e_day;
    }
    sort(flowers, flowers+N, cmp);
    int start = 300;
    int end = 301;
    int res = 0;
    int maxEnd = 0; int maxIdx = 0;
    for(int i = 0 ; i < N ; i++){
        if(flowers[i].s > start && flowers[i].s <= end){
            if(maxEnd < flowers[i].e){
                maxEnd = flowers[i].e;
                maxIdx = i;
            }
            if(flowers[i].e == 1201){
                res++;
                end = maxEnd;
                break;
            }
            
        }
        else{
            if(end >= maxEnd){
                break;
            }
            res++;
            start = end;
            end = maxEnd;
            i--;
        }
    }
    if (end == 1201) {
		cout << res << endl;
	}
	else {
		cout << 0 << endl;
	}
}