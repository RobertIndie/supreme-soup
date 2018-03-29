#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Bridge
{
    int a,b,w;
};

bool compare(const Bridge &a,const Bridge &b)
{
    return a.w<b.w;
}
int n[7];
int find(int k)
{
    return k==n[k]?k:n[k]=find(n[k]);
}

int main()
{
    
    for(int i = 1;i<=7;i++)
        n[i]=i;

    Bridge bs[11] = {
        {1,2,7},
        {2,3,8},
        {1,4,5},
        {2,4,9},
        {2,5,7},
        {3,5,5},
        {4,5,15},
        {4,6,6},
        {5,6,8},
        {6,7,11},
        {5,7,9}
    };

    sort(bs,bs+11,compare);

    vector<Bridge*> result;
    int sum = 0;

    for(int i = 0;i<11;i++)
    {
        int a = find(bs[i].a);
        int b = find(bs[i].b);
        if(a!=b)
        {
            result.push_back(&bs[i]);
            n[a]=b;
            sum += bs[i].w;
        }
    }

    for(vector<Bridge*>::iterator iter=result.begin();iter!=result.end();iter++)
    {
        cout<<(**iter).a<<" "<<(**iter).b<<" "<<endl;
    }

    cout <<"SUM:"<<sum<<endl;

    return 0;
}