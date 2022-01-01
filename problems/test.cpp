#include <iostream>

using namespace std;

int main(){
	int arr[] = {4,1,2,3,7};
	for(int i = 0 ; i < 5 ; i++){
		for(int j = i ; j > 0 ; j--){
			if(arr[j] < arr[j-1]) {
				int temp = arr[i];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
			else break;
		}
	}
	for(int i = 0 ; i < 5 ; i++){
		cout << arr[i] << " " ;
	}

}