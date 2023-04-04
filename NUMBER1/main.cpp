#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
pii p[NM];
string s;

void xuli(){
    int mask = 0, cnt = 0;
    p[0].fi = p[0].se = n + 1;
    for(int i = n; i > 0; i--){
        int u = int(s[i] - '0');
        mask |= MASK(u);
        if(__builtin_popcount(mask) == 10){
            mask = 0;
            cnt++;
            p[cnt] = {i, p[cnt - 1].fi - 1};
        }
        if(i == 1 && mask != 1023){
            if(cnt == 0){
                for(int i = 1; i < 10; i++) if(!BIT(i, mask)){
                    cout << i;
                    return;
                }
            }

            cnt++;
            p[cnt] = {i, p[cnt - 1].fi - 1};
        }
    }

    string ans = "";
    int tmp, pos;
    for(int i = 0; i < 10; i++) if(!BIT(i, mask)){
        tmp = i;
        ans += char(i + '0');
        break;
    }
    cnt--;

    if(!ans.size()){
        ans = "1";
        tmp = 1;
        cnt++;
    }

    if(ans == "0"){
        ans = "1";
        tmp = 1;
    }

    while(cnt){
        mask = 0;
        for(int i = p[cnt].fi; i <= p[cnt].se; i++){
            int u = int(s[i] - '0');
            if(u == tmp){
                p[cnt].fi = i + 1;
                break;
            }
        }

        for(int i = p[cnt].fi; i <= p[cnt].se; i++){
            int u = int(s[i] - '0');
            mask |= MASK(u);
        }

        for(int i = 0; i < 10; i++) if(!BIT(i, mask)){
            ans += char(i + '0');
            tmp = i;
            break;
        }
        cnt--;
    }
    cout << ans;
}
int main()
{
    FastIO
    freopen("NUMBER.INP", "r", stdin);
    freopen("NUMBER.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = ' ' + s;

    xuli();
    return 0;
}
