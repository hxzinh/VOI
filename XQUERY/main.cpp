#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int cnt[NM];
vector<int> val;

struct Node{
    int num, index, last;
    int child[20];
};
struct Trie{
    vector<Node> val;

    void Init(){
        Node tmp;
        tmp.num = 0;
        for(int i = 1; i <= 20; i++) tmp.child[i] = -1;
        tmp.index = val.size();
        val.push_back(tmp);
    }

    void update(int x){
    }
};

void readfile(){
    freopen("XQUERY.INP", "r", stdin);
    freopen("XQUERY.OUT", "w", stdout);
    cin >> q;
}
void sub1(){
    while(q--){
        int type, x;
        cin >> type >> x;
        if(type == 0) val.push_back(x);
        if(type == 1){
            for(int i = 0; i <= val.size(); i++){
                if(val[i] == x){
                    val.erase(val.begin() + i);
                    break;
                }
            }
        }
        if(type == 2) for(int i = 0; i < val.size(); i++) val[i] ^= x;
        if(type == 3){
            int sum = 0;
            sort(ALL(val));
            for(int i = 0; i < x; i++) sum += val[i];
            cout << sum << '\n';
        }
    }
}
void sub2(){
    while(q--){
        int type, x;
        cin >> type >> x;
        if(type == 0){
            val.push_back(x);
            cnt[x]++;
        }
        if(type == 1){
            cnt[x] = (cnt[x] > 0 ? cnt[x] - 1 : 0);
        }
        if(type == 2) for(int i = 0; i < val.size(); i++) if(cnt[val[i]]) val[i] ^= x;
        if(type == 3){
            int sum = 0;
            sort(ALL(val));
            for(int i = 0; i < x; i++) if(cnt[val[i]]) sum += val[i];
            cout << sum << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    readfile();
    if(q <= 1000) sub1();
    else sub2();
    return 0;
}
