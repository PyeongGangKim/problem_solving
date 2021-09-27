#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for(int i = 0 ; i < tc ; i++){
        string str;
        cin >> str;
        while(1){
            string input;
            cin >> input;
            if(input.compare("END") == 0) break;
            if(input[0] == 'I'){ //넣는 경우
                int idx = 2;
                string insertStr;
                int number;
                cin >> insertStr >> number;
                string temp = "";
                for(int i = 0 ; i < number ; i++){
                    temp += str[i];
                }
                temp += insertStr;
                for(int i = number ; i < str.size() ; i++){
                    temp += str[i];
                }
                str = temp;
            }
            else{
                
                int sNum;
                int eNum;

                cin >> sNum >> eNum;
                for(int i = sNum ; i <= eNum ; i++){
                    cout << str[i];
                }
                cout << "\n";
            }
        }
    }
}