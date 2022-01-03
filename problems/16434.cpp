#include <iostream>
#include <vector>



using namespace std;
struct node{
    int type;
    int attack;
    int hp;
    node(int t, int a, int h) : type(t), attack(a), hp(h){}
};
long long N, initAttack;

vector<node> map;
long long MAX = 9e18;
bool check(long long m){
    long long curM = m;
    long long at = initAttack;
    for(int i = 0 ; i < N ; i++){
        if(map[i].type == 1){
            long long curMHp = map[i].hp;
            long long curMAt = map[i].attack;
            long long curCnt = (curMHp - 1) / at + 1;
            curM -= curMAt * (curCnt - 1); 
            if(curM <= 0) return false;
        }
        else{
            long long plusHp = map[i].hp;
            at += map[i].attack;
            if(curM + plusHp >= m) curM = m;
            else curM += plusHp;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> initAttack;

    for(int i = 0 ; i < N ; i++){
        int t,a,h;
        cin >> t >> a >> h;
        map.push_back(node(t,a,h));
      
    }
    long long s = 1;
    long long e = MAX;
    long long res;
    while(s <= e){
        long long m = (s+e) / 2;
        if(check(m)){
            res = m;
            e = m-1;
        }
        else s = m + 1;
    }

    cout << res << "\n";
}