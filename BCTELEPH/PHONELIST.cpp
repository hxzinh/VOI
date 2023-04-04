#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
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

const int NM = 1e4 + 10;
int T, n;
string a[NM];

struct Trie {
    struct Node {
        int num, id, wcnt;
        int child[26];
    };

    vector<Node> tree;

    void build(){
        Node tmp;
        tmp.num = 0;
        for(int i = 0; i < 26; i++) tmp.child[i] = -1;
        tmp.id = tree.size();
        tree.push_back(tmp);
    }

    void desruct(){
        tree.clear();
    }

    void update(const string &s){
        int tmp, id = 0;
        for(int i = 0; i < s.size(); i++){
            tree[id].num++;
            tmp = s[i] - '0';
            if(tree[id].child[tmp] == -1){
                build();
                tree[id].child[tmp] = tree.size() - 1;
            }
            id = tree[id].child[tmp];
        }
        tree[id].num++;
        tree[id].wcnt++;
    }

    int getPreCnt(const string &s){
        int tmp, id = 0;
        for(int i = 0; i < s.size(); i++){
            tmp = s[i] - '0';
            if(tree[id].child[tmp] == -1) return 0;
            id = tree[id].child[tmp];
        }
        return tree[id].num;
    }

    int getWordCnt(const string &s){
        int tmp, id = 0;
        for(int i = 0; i < s.size(); i++){
            tmp = s[i] - '0';
            if(tree[id].child[tmp] == -1) return 0;
            id = tree[id].child[tmp];
        }
        return tree[id].wcnt;
    }

    void delWord(const string &s){
        if(!getPreCnt(s)) return;
        int tmp, id = 0;
        for(int i = 0; i < s.size(); i++){
            tree[id].num--;
            tmp = s[i] - '0';
            id = tree[id].child[tmp];
        }
        tree[id].num--;
        tree[id].wcnt--;
    }
};
Trie tree;

void xuli(){
    for(int i = 1; i <= n; i++){
        if(tree.getPreCnt(a[i]) - 1){
            cout << "NO" << '\n';
            return;
            //cout << tree.getPreCnt(a[i]) << '\n';
        }
    }
    cout << "YES" << '\n';
}
int main()
{
    FastIO
    cin >> T;

    while(T--){
        cin >> n;
        tree.desruct();
        tree.build();
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            tree.update(a[i]);
        }
        xuli();
    }
    return 0;
}
