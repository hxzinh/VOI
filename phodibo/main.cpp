#include <bits/stdc++.h>

using namespace std;
const int NM=3e6+5;
long long n,r,a[NM];

void readfile()
{
    int i;
    freopen("WALK.INP","r",stdin);
    freopen("WALK.OUT","w",stdout);
    cin >> n;
    cin >> r;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
}
void qs(long long L,long long R)
{
    int i,j,pivot;
    i=L;
    j=R;
    pivot=a[(L+R)/2];
    while(i<=j)
    {
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
        if(i<R) qs(i,R);
        if(L<j) qs(L,j);
    }
}
void xuli()
{
    long long gan,i,j,d,c,dem;
    dem=0;
    for (i=1;i<n;i++)
    {
        d=i+1;
        c=n;
        while (d<=c)
        {
            gan=(d+c)/2;
            if (a[gan]-a[i]>r)
            {
                dem=dem+(c-gan+1);
                c=gan-1;
            }
            else
            {
                d=gan+1;
            }
        }
    }
    cout << dem;
}
int main()
{
    readfile();
    qs(1,n);
    xuli();
    return 0;
}
