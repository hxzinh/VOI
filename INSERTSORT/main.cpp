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
int a[1005], b[1005];

int main()
{
    FastIO
    freopen("INSERTSORT.INP", "r", stdin);
    freopen("INSERTSORT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    int key, step = 0;
    /**
    cout << "Buoc " << ++step << ": ";
    for(int u = 1; u <= n; u++) cout << a[u] << " ";
    cout << '\n';
    **/
    for(int i = 2; i <= n; i++){
        key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        bool ok = false;
        for(int u = 1; u <= n; u++){
            if(b[u] != a[u]) ok = true;
            b[u] = a[u];
        }
        //if(!ok) continue;

        cout << "Buoc " << ++step << ": ";
        for(int u = 1; u <= n; u++) cout << a[u] << " ";
        cout << '\n';
    }
    return 0;
}
