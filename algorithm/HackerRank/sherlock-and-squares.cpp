/*
https://www.hackerrank.com/challenges/sherlock-and-squares/problem
*/

#include <iostream>
#include <cmath>

using namespace std;

int squares(int a, int b) {
    int result = 0;
    int min = sqrt(a);
    int max = sqrt(b)+1;
    for(int i=min;i<=max;i++)
    {
        if(i*i>=a && i*i<=b)
            result++;
    }
    return result;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int a;
        int b;
        cin >> a >> b;
        int result = squares(a, b);
        cout << result << endl;
    }
    return 0;
}