#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define MAX 1e9 + 5
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;

struct Point{
    int x = 0, y = 0, v = 0, sta = 0;

    Point(int _x, int _y, int _v, int _sta){
        x = _x, y = _y, v = _v, sta = _sta;
    }
};
vector<Point> p;

struct Node {
    int cnt, sum;
    struct Node *L, *R;
};

struct Node* getNode() {
    struct Node* temp = new struct Node;
    temp -> sum = 0;
    temp -> cnt = 0;
    temp -> L = NULL;
    temp -> R = NULL;
    return temp;
};

struct Node* root;

void update(struct Node* cur, int l, int r, int i, int j, int v) {
    if (r<=i || j<=l) return;
    if (i<=l && r<=j ) cur->cnt += v;
    else
    {
        if(cur->L == NULL)
        cur->L = getNode();
        if(cur->R == NULL)
        cur->R = getNode();
        int m = (l+r) >> 1;
        update(cur->L, l, m, i, j, v);
        update(cur->R, m, r, i, j, v);
    }
    if(!cur->cnt)
    {
        if(cur->L == NULL)
        cur->L = getNode();
        if(cur->R == NULL)
        cur->R = getNode();
        cur->sum = cur->L->sum + cur->R->sum;
    }
    else cur->sum = r - l;
}

bool cmp(const Point &A, const Point &B){
    return A.x < B.x;
}
void sub6(){
    sort(ALL(p), cmp);

    int res = 0;
    root = getNode();
    for(int i = 0; i < (p.size() - 1); i++){
        int len = p[i + 1].x - p[i].x;
        update(root, 0, MAX, p[i].y, p[i].v, p[i].sta);
        res += 1LL * (root -> sum) * len;

    }
    cout << res;
}
void readfile(){
    freopen("RECTAREA.INP", "r", stdin);
    freopen("RECTAREA.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        p.push_back(Point(x, y, v, 1));
        p.push_back(Point(u, y, v, -1));
    }
}
int32_t main(){
    FastIO;
    readfile();
    sub6();
    return 0;
}
