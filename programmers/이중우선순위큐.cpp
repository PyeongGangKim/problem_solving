#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, less<int> > max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    int in = 0;
    int out = 0;
    for(int i = 0 ; i < operations.size() ; i++){
        if(operations[i][0] == 'I'){ // push
            string temp = "";
            for(int j = 2 ; j < operations[i].length() ; j++){
                temp += operations[i][j];
            }
            max_heap.push(stoi(temp));
            min_heap.push(stoi(temp));
            in++;
        }
        else{
            if(in == out) {
                while(!max_heap.empty())max_heap.pop();
                while(!min_heap.empty())min_heap.pop();
                continue;
            }    
            if(operations[i][2] == '1'){
                max_heap.pop();
                out++;
            }
            else{
                min_heap.pop();
                out++;
            }
        }
        if(in == out) {
                while(!max_heap.empty())max_heap.pop();
                while(!min_heap.empty())min_heap.pop();
        }    
    }
    if(in == out){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(max_heap.top());
        answer.push_back(min_heap.top());
    }
    return answer;
}