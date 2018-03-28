#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Land;
class Bridge;

class Land
{
public:
    int id;
    vector<Land*> connectLands;
};

class Bridge
{
public:
    int a;
    int b;
    int t;
};

void dfs(vector<int>* record,vector<Land*>* t_region,Land* land)
{
    if((*record)[land->id])return;
    (*record)[land->id] = 1;
    t_region->push_back(land);
    for(vector<Land*>::iterator iter = land->connectLands.begin();iter!=land->connectLands.end();iter++)
    {
        dfs(record,t_region,*iter);
    }
}

void test(int n,vector<Land*> lands,vector<vector<Land*>>* region)
{
    vector<int> record(n);
    for(vector<Land*>::iterator iter = lands.begin();iter!=lands.end();iter++)
    {
        vector<Land*> t_region;
        dfs(&record,&t_region,*iter);
        region->push_back(t_region);
    }
}

int main()
{
    int n,m;
    int maxday = 0;
    cin >> n >> m;

    vector<Land*> lands;
    vector<Bridge*> bridges;
    for(int i = 0;i<n;i++)
    {
        Land* land = new Land;
        lands.push_back(land);
    }
    for(int i = 0;i<m;i++)
    {
        int a,b,t;
        cin >> a>>b>>t;

        if(t>maxday)maxday=t;
        Bridge* bridge = new Bridge;
        bridge->a = a;
        bridge->b = b;
        bridge->t = t;
        bridges.push_back(bridge);
        Land *la = lands[a];
        Land *lb = lands[b];
        la->connectLands.push_back(lb);
        lb->connectLands.push_back(la);
    }
    for(int i = 0;i<maxday;i++)
    {
        vector<vector<Land*>> region;
        test(n,lands,&region);
        for(vector<Bridge*>::iterator iter = bridges.begin();iter!=bridges.end();iter++)
        {
            Bridge* br = *iter;
            br->t--;
            if(!br->t)
            {
                lands[br->a]->connectLands.erase(find(lands[br->b]->connectLands.begin(),lands[br->b]->connectLands.end(),br->b));
                lands[br->b]->connectLands.erase(find(lands[br->a]->connectLands.begin(),lands[br->a]->connectLands.end(),br->a));
            }
        }
    }
    return 0;
}