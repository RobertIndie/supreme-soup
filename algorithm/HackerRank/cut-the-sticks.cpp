/*
https://www.hackerrank.com/challenges/cut-the-sticks/problem
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> cutTheSticks(vector<int> arr)
{
    int flag = 1;
    int current_sticks_count = arr.size();
    vector<int> result;
    while (flag)
    {
        int min = INT_MAX;
        for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
        {
            min = *iter && *iter < min ? *iter : min;
        }
        cout << "MIN:" << min << endl;
        result.push_back(current_sticks_count * min);
        for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
        {
            if (*iter && !(*iter -= min))
            {
                current_sticks_count--;
            }
        }
        flag = current_sticks_count;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int arr_i = 0; arr_i < n; arr_i++)
    {
        cin >> arr[arr_i];
    }
    vector<int> result = cutTheSticks(arr);
    for (ssize_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;

    return 0;
}