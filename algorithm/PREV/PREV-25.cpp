#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bridge
{
    int a,b,w;
};

int N[10000];



bool compare(const Bridge &a,const Bridge &b)
{
    return a.w<b.w;
}

int find(int k)
{
    return k==N[k]?k:N[k]=find(N[k]);
}

int main()
{
    vector<Bridge> bs;
    int n,m;
    cin>>n>>m;

    for(int i = 1;i<=10000;i++)
    {
        N[i]=i;
    }

    for(int i = 0;i<m;i++)
    {
        Bridge b;
        cin>>b.a>>b.b>>b.w;
        bs.push_back(b);
    }

    for(int i = 1;i<=n;i++)
    {
        Bridge b;
        cin>>b.w;
        if(b.w==-1)continue;
        b.a = 0;
        b.b = i;
        bs.push_back(b);
    }
    sort(bs.begin(),bs.end(),compare);

    int sum = 0;

    int num=0,k;
    for(vector<Bridge>::iterator iter = bs.begin();iter!=bs.end();iter++)
    {
        int a = find(iter->a);
        int b = find(iter->b);
        if(a!=b)
        {
            if(iter->a==0)
            {
                num++;
                k=iter->w;
            }
            sum+=iter->w;
            N[a]=b;
        }
    }
    if(num==1)
    {
        sum-=k;
    }

    cout<<sum;

    return 0;
}