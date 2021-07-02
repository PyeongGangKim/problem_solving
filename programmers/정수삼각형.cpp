#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define pii pair<int, int>
using namespace std;

int solution(vector<vector<int>> triangle)
{
    vector<vector<int>> arr(triangle.size(), vector<int>(triangle.size(), 0));

    arr[0][0] = triangle[0][0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i][0] = arr[i - 1][0] + triangle[i][0];
        arr[i][i] = arr[i - 1][i - 1] + triangle[i][i];
    }

    for (int i = 2; i < arr.size(); i++)
    {
        for (int j = 1; j < i; j++)
        {
            arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + triangle[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        //cout << arr[arr.size() - 1][i] << ' ';
        ans = max(ans, arr[arr.size() - 1][i]);
    }

    return ans;
}