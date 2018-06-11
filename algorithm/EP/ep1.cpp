#include <iostream>
#include <cstring>

using namespace std;

const int NUM = 1000;

int oldMethod()
{
    int array[NUM];
    memset(array,0,sizeof(array));
    int i = 3;
    while(i<NUM)
    {
        array[i] = 1;
        i+=3;
    }
    i = 5;
    while(i<NUM)
    {
        array[i] = 1;
        i+=5;
    }
    int result = 0;
    for(int j = 0;j<NUM;j++) 
        if (array[j]==1)
            result += j;
    cout<<result;
    return 0;
}

int target = 999;

int SumDivisibleBy(int n)
{
    int p = target / n;
    return n*(p*(p+1))/2;
}

int main()
{
    cout<<SumDivisibleBy(3)+SumDivisibleBy(5)-SumDivisibleBy(15);
    return 0;
}