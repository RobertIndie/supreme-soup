#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int n,k,T;
    cin >> n >> k >> T;
    ll turn = 0;
    int number = 0;
    int step = 1;
    ll result = 0;
    int flag = 2;
    for(int i =0;i<T;)
    {
        if(flag<=0)
            step++;
        flag--;
        number += step;
        number = number % k;
        if(turn%n==0)
        {
            //轮到栋栋
            i++;
            result += number;
        }
        turn++;
    }
    cout << result;
    return 0;
}