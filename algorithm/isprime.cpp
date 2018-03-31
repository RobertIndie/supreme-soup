#include <iostream>
using namespace std;
#define N 10000
int dp[N] = {1,1,0};
int prime[N],tot=0;

void init()
{
    for(int i = 2;i<N;i++)
    {
        if(dp[i])continue;
        prime[tot++] = i;
        for(int j = i;i*j<N;j++)
        {
            dp[i*j] = 1;
        }
    }
}

int main()
{
    init();
    for(int i = 0;i<tot;i++)
    {
        cout<<prime[i]<<endl;
    }
    return 0;
}