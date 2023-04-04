#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MAX = 1e4 + 10;
int n, m, t;
long long sum = 0;
vector<int> a;
vector<long long> s, cntSta, cntVisit;

void sub1(){
    int cur = 0;
    s[0] = 1;
    for(int i = 0; i < t * m; i++){
        cur = (cur + a[i % m]) % n;
        if(cur < 0) cur += n;
        s[cur]++;
    }

    for(int i = 0; i < n; i++) cout << s[i] << " ";
}
void sub3(){
    int cur = 0;
    for(int i = 0; i < m; i++){
        cur = (cur + a[i % m]) % n;
        if(cur < 0) cur += n;
        s[cur]++;
    }

    for(int i = 0; i < n; i++) s[i] *= t;
    s[0]++;
    for(int i = 0; i < n; i++) cout << s[i] << " ";
}
void sub4(){
    int cur = 0;
    for(int i = 0; i < n; i++){
        cur = (cur + a[i % m]) % n;
        if(cur < 0) cur += n;
        s[cur]++;
    }
    for(int i = 0; i < n; i++) s[i] = s[i] * (t / n);
    t = t % n;
    for(int i = 0; i < t; i++){
        cur = (cur + a[i % m]) % n;
        if(cur < 0) cur += n;
        s[cur]++;
    }
    s[0]++;

    for(int i = 0; i < n; i++) cout << s[i] << " ";
}
void full(){
    int cur = 0;
    for(int i = 0; i < n; i++){
        cur = (cur + sum) % n;
        if(cur < 0) cur += n;
        cntSta[cur]++;
    }
    for(int i = 0; i < n; i++) cntSta[i] = cntSta[i] * (t / n);
    for(int i = 0; i < t % n - 1; i++){
        cur = (cur + sum) % n;
        if(cur < 0) cur += n;
        cntSta[cur]++;
    }
    cntSta[0]++;

    cur = 0;
    for(int i = 0; i < m; i++){
        cur = (cur + a[i]) % n;
        if(cur < 0) cur += n;
        cntVisit[cur]++;
    }

    for(int i = 0; i < n; i++)
       for(int j = 0; j < n; j++) s[(i + j) % n] += 1LL * cntSta[i] * cntVisit[j];
    s[0]++;

    for(int i = 0; i < n; i++) cout << s[i] << " ";
}
int32_t main()
{
    FastIO
    freopen("JOG.INP", "r", stdin);
    freopen("JOG.OUT", "w", stdout);
    cin >> n >> t >> m;
    a = vector<int>(m + 1);
    s = vector<long long>(n + 1);
    cntSta = vector<long long>(n + 1);
    cntVisit = vector<long long>(n + 1);
    for(int i = 0; i < m; i++){
        cin >> a[i];
        sum += a[i];
    }
    sum %= n;


    if(n == 1) cout << 1LL * m * t + 1;
    else if(m == 1) sub4();
    else if(t <= 100) sub1();
    else if(sum == 0) sub3();
    else full();


        /**
    sub1();
    cout << '\n';
    for(int i = 0; i < n; i++) s[i] = 0;
    full();
    **/

    return 0;
}

/* Author: hxzinh */
