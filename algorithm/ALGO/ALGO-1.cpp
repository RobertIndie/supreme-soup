#include <iostream>

using namespace std;

int main()
{
    int* arr = 0;
    int* ask = 0;
    int n;
    cin >> n;
    arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    for(int i = 0;i<m;i++)
    {
        int l,r,k;
        cin >> l >> r >> k;
        int aan = r-l+1;
        int* aa = new int[aan];
        for(int i=0;i<aan;i++)
            aa[i] = arr[l+i-1];
        for(int i = 0;i<aan;i++)
        {
            for(int j = i;j<aan;j++)
            {
                if(aa[i]<aa[j])
                {
                    int temp = aa[i];
                    aa[i] = aa[j];
                    aa[j] = temp;
                }
            }
        }
        cout<<aa[k-1]<<endl;
        delete [] aa;
    }
    return 0;
}