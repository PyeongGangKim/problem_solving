#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;
vector<int> check_num; // 가지고 있는 숫자들
bool check[10];
vector<char> alpha;// 입력받은 알파벳
vector<string> values;//입력받은 문자열들
int num;
int num_alpha;// 입력받은 알파벳의 갯수
int alpha_get_num[26]; // 알파벳과 숫자를 대응시킬 array

void cal_str(){
    for(int i = 0 ; i < num_alpha ; i++){
        int a = alpha[i] - 'A';
        int n = check_num[i];
        alpha_get_num[a] = n;
    }
    int cur_result = 0;
    for(int i = 0 ; i < values.size() ; i++){
        int temp_result = 0 ;
        for(int j = 0 ; j < values[i].length() ; j++){
            temp_result *= 10;
            temp_result += alpha_get_num[values[i][j] - 'A'];
        }
        cur_result += temp_result;
    }
    result.push_back(cur_result);
}
void dfs(int count){
    if(count == num_alpha){
        cal_str();
    }
    else{
        for(int i = 10 - num_alpha; i <= 9 ; i++){
            if(!check[i]){
                check_num.push_back(i);
                check[i] = true;
                dfs(count+1);
                check[check_num.back()] = false;
                check_num.pop_back();
            }
        }
    }
    return;
}
int check_len(){
    bool alpha_ch[26] = {false,};
    int number = 0;
    for(int i = 0 ; i < num ; i++){
        string temp = values[i];
        for(int j = 0 ; j < values[i].length() ; j++){
            if(alpha_ch[values[i][j] - 'A'] == false ){
                alpha_ch[values[i][j] - 'A'] = true;
                alpha.push_back(values[i][j]);
                number++;
            }
        }
    }
    return number;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> num;
    string temp;
    for(int i = 0 ; i < num ; i++){
        cin >> temp;
        values.push_back(temp);
    }
    num_alpha = check_len();
    dfs(0);
    sort(result.begin(),result.end());
    cout << result.back() << "\n";
}