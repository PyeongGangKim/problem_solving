#include <iostream>

using namespace std;

int testcase;
int studentNum;
int check[100001];
int selectNum[100001];

int noTeamStudentCheck(){
    int cnt = 0 ;
    for(int i = 1 ; i <= studentNum ; i++){
        if(check[i] != 2) cnt++;
    }
    return cnt;
}
void search(int curNode){
    check[curNode]++;
    int nextNode = selectNum[curNode];
    if(check[nextNode] != 2 && check[nextNode] != -1){
        search(nextNode);
    }
    if(check[curNode] != 2) check[curNode] = -1;

}
void dfs(){
    for(int i = 1 ; i <= studentNum ; i++){
        if(check[i] == 0){
            search(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> testcase;
    for(int i = 0 ; i < testcase ; i++){
        cin >> studentNum;
        for(int j = 1 ; j <= studentNum ; j++){
            cin >> selectNum[j];
            check[j] = 0;
        }
        dfs();
        cout << noTeamStudentCheck() << "\n";
    }
    
    


}