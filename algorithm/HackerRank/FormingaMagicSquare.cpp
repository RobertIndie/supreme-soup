#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int formingMagicSquare(vector < vector<int> > s) {
    map<int,int> temp;
    int arr[9];
    int _t = 0;
    for(vector < vector<int> > ::iterator iter=s.begin();iter!=s.end();iter++)
    {
        for(vector<int>::iterator subIter=iter->begin();subIter!=iter->end();subIter++)
        {
            arr[_t++]=*subIter;
        }
    }
    
    //row
    for(int i=0;i<9;i+=3)
    {
        int sum = arr[i]+arr[i+1]+arr[i+2];
        if(temp.find(sum)==temp.end())
        {
            temp.insert(pair<int,int>(sum,1));
        }
        else
        {
            temp[sum]++;
        }
    }

    //column
    for(int i=0;i<3;i++)
    {
        int sum = arr[i]+arr[i+3]+arr[i+6];
        if(temp.find(sum)==temp.end())
        {
            temp.insert(pair<int,int>(sum,1));
        }
        else
        {
            temp[sum]++;
        }
    }

    //diagonal
    {
        int sum = arr[0] + arr[4] + arr[8];
        if(temp.find(sum)==temp.end())
        {
            temp.insert(pair<int,int>(sum,1));
        }
        else
        {
            temp[sum]++;
        }
    }
    {
        int sum = arr[2] + arr[4] + arr[6];
        if(temp.find(sum)==temp.end())
        {
            temp.insert(pair<int,int>(sum,1));
        }
        else
        {
            temp[sum]++;
        }
    }

    int max = 0;
    int num = 0;
    for(map<int,int>::iterator iter=temp.begin();iter!=temp.end();iter++)
    {
        if(iter->second>max)
        {
            max = iter->second;
            num = iter->first;
        }
    }

    int result = 0;

    //row
    for(int i=0;i<9;i+=3)
    {
        if(arr[i]+arr[i+1]+arr[i+2]!=num)
        {
            int _a[3] = {abs(arr[i]-num),abs(arr[i+1]-num),abs(arr[i+2]-num)};
            sort(_a,_a+3);
            result += abs(_a[0]-num);
        }
    }

    //column
    for(int i=0;i<3;i++)
    {
        if(arr[i]+arr[i+3]+arr[i+6]!=num)
        {
            int _a[3] = {abs(arr[i]-num),abs(arr[i+3]-num),abs(arr[i+6]-num)};
            sort(_a,_a+3);
            result += abs(_a[0]-num);
        }
    }

    //diagonal
    {
        if(arr[0]+arr[4]+arr[8]!=num)
        {
            int _a[3] = {abs(arr[0]-num),abs(arr[4]-num),abs(arr[8]-num)};
            sort(_a,_a+3);
            result += abs(_a[0]-num);
        }
    }
    {
        if(arr[2]+arr[4]+arr[6]!=num)
        {
            int _a[3] = {abs(arr[2]-num),abs(arr[4]-num),abs(arr[6]-num)};
            sort(_a,_a+3);
            result += abs(_a[0]-num);
        }
    }
    return result;
}

int main() {
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> s[s_i][s_j];
       }
    }
    int result = formingMagicSquare(s);
    cout << result << endl;
    return 0;
}