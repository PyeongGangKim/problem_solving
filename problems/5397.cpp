#include <iostream>
#include <list>
#include <string>
using namespace std;
list<char> answer;
list<char> :: iterator t;

void print(){
    for(t = answer.begin() ; t != answer.end() ; t++) cout << *t;
    cout << "\n";
}
void operation(string str){
    t = answer.begin();
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '>'){
            if(t != answer.end()){
                t++;
            }
        }
        else if(str[i] == '<'){
            if(t != answer.begin()){
                t--;
            }
        }
        else if(str[i] == '-'){
            if(t != answer.begin()){
                t = answer.erase(--t);
            }
        }
        else{
            answer.insert(t,str[i]);
        }
    }
    print();
    answer.clear();
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string str;

    int testcase;
    cin >> testcase;

    for(int i = 0 ; i < testcase ; i++){
        cin >> str;
        operation(str);
    }
}