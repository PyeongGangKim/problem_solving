#include <iostream>

using namespace std;

int num = 0;
void add(int temp){
    num |= (1 << temp);
}
void remove(int temp){
    num &= ~(1 << temp);
}
bool check(int temp){
    if(num & (1 << temp)) return true;
    else return false;
}
void toggle(int temp){
    num ^= (1 << temp);
}
void all(){
    num = (1 << 21) - 1;
}
void empty(){
    num = 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int testCase;
    cin >> testCase;
    string str;
    int temp;
    for(int i = 0 ; i < testCase ; i++){
        cin >> str;
        if(str == "add") {
            cin >> temp;
            add(temp);
        }
        else if(str == "remove") {
            cin >> temp;
            remove(temp);
        }
        else if(str == "check") {
            cin >> temp;
            if(check(temp)) cout << "1\n";
            else cout << "0\n";
        }
        else if(str == "toggle") {
            cin >> temp;
            toggle(temp);
        }
        else if(str == "all") all();
        else empty();
    }    

}