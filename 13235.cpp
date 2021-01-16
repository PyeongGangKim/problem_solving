#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;

    for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - 1 - i]) {
			printf("false");
			return 0;
		}
	}
	printf("true");
	return 0;
}