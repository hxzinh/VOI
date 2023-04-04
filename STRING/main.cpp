#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int x, y, k;
int a[30];
bool ok;
vector<string> ans;
vector<int> xet;

void backtrack(string res){
    if(res.length() >= x) {
        ans.push_back(res);
        if(ans.size() == k) throw -1;
        if(res.length() == y) return;

    }
    for(auto i : xet){
        if(a[i] > 0){
            a[i]--;
            string newRes = res + char(i + 96);
            backtrack(newRes);
            a[i]++;
        }
    }
    return;
}
void readfile(){
    freopen("STRING.INP", "r", stdin);
    freopen("STRING.OUT", "w", stdout);
    while(cin >> x >> y >> k){
        ok = true;
        ans.clear();
        xet.clear();
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= 26; i++){
            cin >> a[i];
            if(a[i] > 0) xet.push_back(i);
            if(a[i] < 0) ok = false;
        }
        if(x > y) ok = false;
        if(!ok){cout  << "NO" << '\n' << '\n'; continue;}
        string res = "";
        try {
            backtrack(res);
        } catch (...){
            cout << "YES" << '\n';
            for(int i = 0; i < k; i++) cout << ans[i] << " ";
            cout << '\n';
            continue;
        }
        cout << "NO" << '\n' << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    return 0;
}
