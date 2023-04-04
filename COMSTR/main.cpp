#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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
int n, m, m1, m2, k;
int id[NM], cnt[NM][30], numDiff[NM];
string s;

struct Data {
    int u, v, id;
};

void sub1() {
    string str[3];
    for(int i = 0; i < m1 + m2; i++) {
        if(i < m2) str[1] += s[i];
        else str[0] += s[i];
    }

    while(str[2].size() < m) {
        str[2] = str[1] + str[0];
        str[0] = str[1];
        str[1] = str[2];
    }

    int res = 0;
    for(int i = 0; i < m; i++) {
        if(s[i] != str[2][i]) res++;
    }

    cout << res;
}
void sub2() {
    n = m1 + m2;
    int res = INF;
    for(int mask = 0; mask < MASK(n); mask++) {
        string str[3];
        for(int i = 0; i < n; i++) {
            if(i < m2) str[1] += BIT(mask, i) ? 'B' : 'A';
            else str[0] += BIT(mask, i) ? 'B' : 'A';
        }

        while(str[2].size() < m) {
            str[2] = str[1] + str[0];
            str[0] = str[1];
            str[1] = str[2];
        }

        int ans = 0;
        for(int i = n; i < m; i++)
            if(s[i] != str[2][i]) ans++;

        //cout << str[2] << " " << ans << '\n';
        minimize(res, ans);
    }

    cout << res;
}
void xuli() {
    n = m1 + m2;
    for(int i = 0; i < m1 + m2; i++) id[i] = i;

    int pre = m2, len = m1 + m2;
    while(len < m) {
        int i = len;
        len += pre;
        for(int j = i; j < len; j++) {
            id[j] = id[j - i];
            if(j >= m) break;
        }
        pre = i;
    }

    for(int i = 0; i < m; i++) cnt[id[i]][s[i] - 'A']++;

    //for(int i = 0; i < m; i++) cout << id[i] << " ";
    //cout << '\n';

    int res = 0;
    vector<Data> vec;
    for(int i = 0; i < n; i++) {
        pii maxEq = {-1, -1};
        for(int j = 0; j < 26; j++) {
            numDiff[i] += cnt[i][j];
            if(maximize(maxEq.fi, cnt[i][j] + (j != (s[i] - 'A')))) maxEq.se = j;
        }

        if(maxEq.se == (s[i] - 'A')) res += numDiff[i] - maxEq.fi;
        else vec.push_back({cnt[i][s[i] - 'A'], maxEq.fi, i});
    }

    sort(ALL(vec), [](const Data A, const Data B){
        return (A.v - A.u) > (B.v - B.u);
    });

    for(int i = 0; i < vec.size(); i++) {
        //cout << vec[i].fi << " " << vec[i].se << '\n';
        int u = vec[i].u, v = vec[i].v, id = vec[i].id;
        if(i < k && v > u) res += numDiff[id] - v;
        else res += numDiff[id] - u;
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("COMSTR.INP", "r", stdin);
    freopen("COMSTR.OUT", "w", stdout);
    cin >> m >> m1 >> m2 >> k;
    cin >> s;

    xuli();
    return 0;
}

/* Author: hxzinh */
