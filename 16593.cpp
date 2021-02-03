#include <iostream>
#include <queue>

using namespace std;

queue<pair<long,int> >q;
long long target;
long long A;
int BFS(){
    while(!q.empty()){
        long long num = q.front().first; int cnt = q.front().second;
        q.pop();
        if(num == target) return cnt;
        long long newNum1, newNum2;
        newNum1 = num*2;
        newNum2 = num*10 + 1;
        if(newNum1 <= target) q.push(make_pair(newNum1, cnt+1));
        if(newNum2 <= target) q.push(make_pair(newNum2, cnt+1));
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> A >> target;
    q.push(make_pair(A,1));
    cout << BFS() << "\n";
}