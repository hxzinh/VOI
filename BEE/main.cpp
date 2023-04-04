#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int T;

void Sub1()
{
    while (T--)
    {
        double a, b, bee, s; cin >> a >> b >> bee >> s;

        if (bee <= a)
        {
            double ti = s / (a + b);
            cout << int(bee * ti) << '\n';
        }

        else if (bee <= b)
        {
            double ti = s / (bee + b);
            double Sbee = bee * ti, Sb = b * ti, Sa = a * ti;
            ti = (s - Sb - Sa) / (a + b);
            cout << int(Sbee + bee * ti) << '\n';
        }

        else
        {
            bool Right = false;
            double Ta = 0, Tbee = 0, Tb = s, res = 0;
            while (true)
            {
                if (!Right)
                {
                    double ti = (Tb - Tbee) / (b + bee);
                    Tb -= b * ti;
                    Ta += a * ti;
                    Tbee += bee * ti;
                    res += bee * ti;
                    Right = true;
                }
                else
                {
                    double ti = (Tbee - Ta) / (a + bee);
                    Tb -= b * ti;
                    Ta += a * ti;
                    Tbee -= bee * ti;
                    res += bee * ti;
                    Right = false;
                }
                if (Tb - Ta < 0.0001) break;
            }
            cout << int(res) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("BEE.INP", "r", stdin);
    freopen("BEE.OUT", "w", stdout);
    cin >> T;

    Sub1()
    return 0;
}
