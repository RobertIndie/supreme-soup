/*
https://www.hackerrank.com/challenges/sherlock-and-squares/problem
*/

#include <iostream>
#include <cmath>

using namespace std;

int squares(int a, int b) {
    return (int)sqrt(b)-(int)sqrt(a-1);
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