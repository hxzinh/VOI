#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e3 + 10;
const int MOD = 1e9 + 7;
int n;
int query[NM], pw[NM], h[NM];
string s;

bool kiemtra(int x){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == s[i + x]) cnt++;
        else cnt = 0;
        if(cnt >= x) return true;
    }
    return false;
}
void sub2(int k){
    int l = 1, r = s.size() / 2, res = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(kiemtra(mid)){
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << res << '\n';
}
bool check(int x, int k){
    for(int i = 0; i < s.size(); i++){
        int cnt = 0, numDiff = 0;
        for(int j = i + x; j < s.size(); j++){
            if(s[j] == s[j - x]) cnt++;
            else numDiff++;
        }
        if(cnt >= x && numDiff == k) return true;
    }
    return false;
}
void sub1(int k){
    int res = 0;
    for(int x = 1; x <= s.size() / 2; x++){
        for(int i = 0; i + 2 * x - 1 < s.size(); i++){
            int cnt = 0, numDiff = 0;
            for(int j = i + x; j <= i + 2 * x - 1; j++){
                if(s[j] == s[j - x]) cnt++;
                else numDiff++;
            }
            if(numDiff == k) maximize(res, x);
        }
    }
    cout << res << '\n';
}
int getHash(int l, int r) {
	return 1LL * (h[r] - h[l - 1] + MOD) * pw[NM - r] % MOD;
}

void xuli(){
    s = ' ' + s;
    pw[0] = 1;
    for(int i = 1 ; i <= 3003 ; i++)
    pw[i] = 1LL*pw[i-1]*256%MOD;

    for(int i = 1 ; i <= s.size() ; i++)
    h[i] = (1LL*h[i-1]+1LL*pw[i]*s[i]%MOD)%MOD;


    while(n--)
    {
        int d;
        cin >> d;

        int cnt = 0;
        vector <int> V;
        for(int u = 1 ; u <= s.size() ; u++)
        for(int i = u ; i <= s.size() ; i++)
        {
            int l = i - u + 1;
            int r = i;

            int ll = i+1;
            int rr = i + u;

            if(ll > s.size() || rr > s.size()) continue;

            if(getHash(l,r) == getHash(ll,rr))
            {
                cnt=u;
                break;
            }

        }
        cout<<cnt<<'\n';
    }
}
int32_t main()
{
    FastIO
    freopen("VIRUS.INP", "r", stdin);
    freopen("VIRUS.OUT", "w", stdout);
    cin >> n;
    cin >> s;
    for(int i = 1; i <= n; i++) cin >> query[i];

    if(s.size() <= 300){
        for(int i = 1; i <= n; i++) sub1(query[i]);
    } else {
        xuli();
    }
    return 0;
}
