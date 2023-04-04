#include <bits/stdc++.h>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'

using namespace std;
const int MOD = 998244353;
const int MOD2 = 1e7 + 19;
string S;
using ii = pair <int, int>;
using ll = long long;
using ld = long double;
#define MAX 5000006
long long H[MAX],pw[MAX];
int getHash(int l, int r) {
	return 1LL * (H[r] - H[l - 1] + MOD) * pw[MAX - r] % MOD;
}
bool ok(int l)
{
	vector<int> codes;
	for (int i = 1; i <= S.length() - l + 1; i++)
		codes.push_back(getHash(i, i + l - 1));
        sort(codes.begin(), codes.end());
 
	for (int i = 0; i < codes.size(); i++) {
		bool okPrev = i == 0 || codes[i] != codes[i - 1];
		bool okNext = i == (int)codes.size() - 1 || codes[i] != codes[i + 1];
		if (okPrev && okNext) return true;
	}
	return false;
}
vector <int> V;
signed main(void)
{
    ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    freopen("unique-substring.inp","r",stdin);
    freopen("unique-substring.out","w",stdout);
    cin>>S;
    if(S.length() >= 5000005)
    {
        cout<<S;
        return 0;
    }
    pw[0] = 1;
    for (int i = 1; i < MAX; i++) pw[i] = 1LL * pw[i - 1] * 256 % MOD;
    for (int i = 1; i <= S.length(); i++) H[i] = (H[i - 1] + 1LL * S[i - 1] * pw[i - 1]) % MOD;
 
    int l = 1 , r = S.length();
    int x = 1e9;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(ok(mid))
        {
            r = mid - 1;
            if(x > mid)
            {
                x = mid;
            }
        }
        else l = mid+1;
    }
    vector<ii> codes;
    for (int i = 1; i <= S.length() - x + 1; i++)
	codes.push_back({ getHash(i, i + x - 1),i});
    sort(ALL(codes));
    int TMP = 0;
    for(int i = 0 ; i < codes.size() ; i++)
    {
        if(i == 0) TMP = codes[i].first;
        else
        {
            if(TMP == codes[i].first)
            {
                codes[i].first = -1;
                codes[i-1].first = - 1;
            }
            else
            {
                TMP = codes[i].first;
            }
        }
    }
    vector <int> V;
    for(ii i : codes) if(i.first != -1) V.push_back(i.second);
    if(V.size() == 0)
    {
        cout<<S;
        return 0;
    }
    string Ans = "";
    for(int j = V[0] - 1 ; j <= V[0] + x - 2 ; j++) Ans +=S[j];
    for(int i = 1 ; i < V.size() ; i++)
    {
        string Tmp = "";
        for(int j = V[i] - 1 ; j <= V[i] + x - 2 ; j++) Tmp +=S[j];
        {
            if(Tmp < Ans){
                Ans = Tmp;
            }
        }
    }
    cout<<Ans;
    return 0;
}