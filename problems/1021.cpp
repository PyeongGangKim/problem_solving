#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    deque<int> dq;
    int res = 0;
    for(int i = 1 ; i <= N ; i++){
        dq.push_back(i);
    }
    for(int i = 0 ; i < M ; i++){
        int target;
        cin >> target;
        int front_cnt = 0;
        int back_cnt = 0;
        deque<int>::iterator iter;
        deque<int>:: reverse_iterator riter;
        for(iter = dq.begin() ; iter != dq.end() ; iter++){
            if(*iter == target) break;
            front_cnt++;
        }
        for(riter = dq.rbegin() ; riter != dq.rend() ; riter++){
            if(*riter == target) break;
            back_cnt++;
        }

        if(back_cnt < front_cnt){ //뒤로 가는 게 더 작다면,
            //뒤에꺼를 빼서 앞으로 넣기
            while(dq.front() != target){
                res++;
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
        }
        else{
            //앞에꺼를 빼서 뒤로 넣기
            while(dq.front() != target){
                res++;
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
        }
        dq.pop_front();
    }
    cout << res << "\n";
}