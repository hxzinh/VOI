#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n, k, r, t;
int numCam = 0;
bool cx[NM];
vector<int> trace;

void readfile(){
    freopen("CAMERA.INP", "r", stdin);
    freopen("CAMERA.OUT", "w", stdout);
    cin >> n >> k >> r >> t;
    for(int i = 1; i <= k; i++){
        int u; cin >> u;
        cx[u] = true;
    }
}
void xuli(){
    for(int i = 1; i <= r; i++) if(cx[i]) numCam++;
    if(numCam < t){
        for(int i = r; i >= 1; i--) if(!cx[i]) {
            if(numCam >= t) break;
            numCam++;
            cx[i] = true;
            trace.push_back(i);
        }
    }

    for(int i = 2; i <= n - r + 1; i++){
        numCam += cx[i + r - 1] - cx[i - 1];
        if(numCam < t){
            numCam++;
            cx[i + r - 1] = true;
            trace.push_back(i + r - 1);
        }
    }
    int res = trace.size();
    cout << res << '\n';
    for(int u : trace) cout << u << " ";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
