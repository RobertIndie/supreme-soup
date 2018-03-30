#include <iostream>
#include <numeric>

using namespace std;

int gcd(int a,int b)
{
    if(a<b)gcd(b,a);
    else if(b==0)return a;
    else return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << lcm(lcm(a,b),c);
    return 0;
}