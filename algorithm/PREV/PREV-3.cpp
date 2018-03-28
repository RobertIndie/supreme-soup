#include <iostream>

using namespace std;

int main()
{
    int n,k,T;
    cin >> n >> k >> T;
    int step = 1;
    int number = 1;
    int times = 0;
    int result = 1;
    for(int i = 0;i!=T-1;)
    {
        number += step;
        step++;
        while(number>=k-1)
        {
            number-=k;
        }
        times ++;
        if(times%n==0)
        {
            i++;
            result+=number;
        }
    }
    cout<<result;
    return 0;
}