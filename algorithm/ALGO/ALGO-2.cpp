#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b)
{
    if(a<b)return gcd(b,a);
    else if(b==0)return a;
    else return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}

int main()
{
    ll n;
    cin >> n;
    for(int i = n ;i>0;i--)
    {
        for(int j = n;j>0;j--)
        {
            for(int k = n;k>0;k--)
            {
                if(i!=j&&i!=k&&j!=k)
                {
                    cout<<lcm(lcm(i,j),k);
                    return 0;
                }
            }
        }
    }
    return 0;
}