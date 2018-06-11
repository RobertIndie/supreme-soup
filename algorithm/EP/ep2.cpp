#include <iostream>

using namespace std;

int oldMethod()
{
    int target = 4000000;
    int a = 0,b = 1;
    int result = 0;
    while(a+b<=target)
    {
        int t = a + b;
        if(t%2==0)
        {
            result += t;
            cout<<"Even:";
        }
        cout<<t<<endl;
        a = b;
        b = t;
    }
    cout<<"Result:"<<result<<endl;
    return 0;
}

int main()
{
    const int target = 4000000;
    int a = 0,b = 2;
    int result = b;
    while(a+b<=target)
    {
        int t = a+4*b;
        cout<<t<<endl;
        result += t;
        a = b;
        b = t;
    }
    cout<<"Result:"<<result<<endl;
    return 0;
}