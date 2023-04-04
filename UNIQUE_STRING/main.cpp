#include <bits/stdc++.h>
#define ll long long
#define MMAX 5000100
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int,int>

using namespace std;
const int NM=MMAX;
const int MODUL=998244353;
const int BASE=256;
string s;
ll n,pos=0;
ll h[NM],index[NM];
bool cx[NM];

void readfile(){
    freopen("UNIQUE_SUBSTRING.INP","r",stdin);
    freopen("UNIQUE_SUBSTRING.OUT","w",stdout);
    cin >> s;
    n=s.length();
    s=' '+s;
    index[0]=1;
    for(int i=1;i<MMAX;i++) index[i]=1LL*index[i-1]*BASE%MODUL;
    for(int i=1;i<=s.length();i++) h[i]=(h[i-1]+1LL*s[i]*index[i])%MODUL;
    memset(cx,true,sizeof(cx));
}
int getHash(int l, int r) {
    return 1LL * (h[r] - h[l - 1] + MODUL) * index[MMAX - r] % MODUL;
}
bool check(int l)
{
	vector<int> codes;
	for (int i = 1; i <= n - l + 1; i++)
		codes.push_back(getHash(i, i + l - 1));
    sort(codes.begin(), codes.end());
	for (int i = 0; i < codes.size(); i++) {
		bool okPrev = i == 0 || codes[i] != codes[i - 1];
		bool okNext = i == (int)codes.size() - 1 || codes[i] != codes[i + 1];
		if (okPrev && okNext) return true;
	}
	return false;
}
void xuli(){
    string ans="",tam="";
    ll d=0,c=n,g,res=1e9;
    while(d<=c){
        g=(d+c)/2;
        if(check(g)){
            res=g;
            c=g-1;
        }
        else d=g+1;
    }
    vector <ii> codes;
    for(int i=1;i<=n-res+1;i++){
        codes.push_back({getHash(i,i+res-1),i});
    }
    sort(codes.begin(),codes.end());
    int t=0;
    for(int i=0;i<codes.size();i++){
        if(i==0) t=codes[i].first;
        else{
            if(t==codes[i].first){
                codes[i].first=-1;
                codes[i-1].first=-1;
            }
            else t=codes[i].first;
        }
    }
    vector <int> u;
    for(ii i : codes) if(i.first != -1) u.push_back(i.second);
    if(u.empty()){
        cout << s;
        return;
    }
    for(int i=u[0];i<u[0]+res;i++) ans+=s[i];
    for(int i=1;i<u.size();i++){
        string tam="";
        for(int j=u[i];j<u[i]+res;j++){
            tam+=s[j];
        }
        if(tam<ans) ans=tam;
    }
    cout << ans;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
