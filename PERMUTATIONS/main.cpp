#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n;
int cnt[1000005];
vector<int> ans;

int main()
{
    FastIO
    cin >> n;

    queue<int> q;
    if(n >= 2){
        q.push(2);
        q.push(1);
    } else q.push(1);
    for(int i = 3; i <= n; i++) q.push(i);

    int pre = -INF;
    bool ok = true;
    while(q.size()){
        int u = q.front();
        q.pop();

        if(cnt[u] > 1) {
            cout << "NO SOLUTION";
            ok = false;
            break;
        }

        if(abs(u - pre) != 1) {
            ans.push_back(u);
            pre = u;
        } else {
            cnt[u]++;
            q.push(u);
        }
    }

    if(ok) for(int u : ans) cout << u << " ";

    return 0;
}
