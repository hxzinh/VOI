#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;

    double range(Point p)
    {
        return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
    }

};

int n;
Point a[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("INP","r",stdin);
    freopen("OUT","w",stdout);

    cin >> n;
    for(int i  = 1 ; i <= n; i++) cin >> a[i].x >> a[i].y;

    double l = -1e9 , r = 1e9;
    Point p1,p2;
    p1.x = p1.y = p2.x = p2.y = 0;
    double res = 1e9;

    for (int i = 1; i <= 100; ++i)
    {
        double R1 = 0, R2 = 0, x1 = l + (r - l) / 3, x2 = r - (r - l) / 3;
        p1.x = x1;
        p2.x = x2;
        for (int i = 1; i <= n; i++)
        {
            R1 = max(R1, p1.range(a[i]));
            R2 = max(R2, p2.range(a[i]));
        }
        if(R1 <= R2)  r = x2;
        else
        {
            res = min(R1, R2);
            l = x1;
        }
    }
    cout<<fixed << setprecision(2)<<res;

    return 0;
}
