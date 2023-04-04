#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int L, n;
int a[15];

int Remainder(string str, int R){
    int len = str.length();

    int Num, Rem = 0;
    for (int i = 0; i < len; i++){
        Num = Rem * 10 + (str[i] - '0');
        Rem = Num % R;
    }
    return Rem;
}
void sub2(){
    string s = "";
    for (int i = 1; i <= L; ++i) s += '9';

    int cnt = 0;
    char r = '9';
    while (true){
        for (int i = 1; i <= n; ++i) if (!Remainder(s, a[i]))
        for (int j = i + 1; j <= n; ++j) if (!Remainder(s, a[j])){
            cout << L << " " << r;
            return;
        }

        if (r == '1'){
            r = '9';
            if (--L == 0) break;
        } else r--;

        s = "";
        for (int i = 1; i <= L; ++i) s += r;
    }
    cout << "1 0";
}


void sub1(){
    int t = 0, h = 1, d = 0;
    for(int i = 0; i < L; i++){
        t = t * 10 + 1;
        for(int bac = 1; bac < 10; bac++){
            int tmp = t * bac;
            int cnt = 2;
            for(int i = 1; i < n; i++)
            for(int j = i + 1; j <= n; j++) if(tmp % a[i] == 0 && tmp % a[j] == 0){
                if(h < i + 1){h = i + 1; d = bac;}
                else if(d < bac) d = bac;
            }
        }
    }
    cout << h << " " << d;
}
int32_t main(){
    FastIO
    freopen("MONODIGIT.INP", "r", stdin);
    freopen("MONODIGIT.OUT", "w", stdout);
    cin >> L >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sub2();
    return 0;
}
