/*
https://www.hackerrank.com/challenges/chocolate-feast/problem
*/

#include <bits/stdc++.h>

using namespace std;

int chocolateFeast(int n, int c, int m)
{
    int wrappers = n / c;
    int result = wrappers;
    while (wrappers >= m)
    {
        int temp = wrappers / m;
        wrappers = temp + wrappers % m;
        result += temp;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++)
    {
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int result = chocolateFeast(n, c, m);
        cout << result << endl;
    }
    return 0;
}