#include <bits/stdc++.h>
#define ll long long
#define INF 1E18
#define MASK(x) (1LL << (x))
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 2e3 + 10;
int n;
int cop[NM], rankA[NM], rankB[NM], pos[NM];

struct Binary{
    int first, second, third;

    Binary(int _first = 0, int _second = 0, int _third = 0){
        if(_first < _second) swap(_first, _second);
        if(_third > _first){
            int tam = _third;
            _third = _second;
            _second = _first;
            _first = tam;
        } else if(_third > _second) swap(_third, _second);

        if(_first == _second){
            first = _first + 1;
            second = _third;
            third = -1;
        } else if(_second == _third){
            if(_first == _second + 1){
                first = _first + 1;
                second = third = -1;
            } else{
                first = _first;
                second = _second + 1;
                third = -1;
            }
        } else{
            first = _first;
            second = _second;
            third = _third;
        }
    }

    int compare(const Binary &A) const {
        #define COMPARE(x, y) ((x) > (y)) - ((x) < (y))
        if(first != A.first) return COMPARE(first, A.first);
        else if(second != A.second) return COMPARE(second, A.second);
            else return COMPARE(third, A.third);
    }

    #define BOOL_OPERATOR(x) bool operator x (const Binary &a) const {return compare(a) x 0;}
    BOOL_OPERATOR(<) BOOL_OPERATOR(>)
    BOOL_OPERATOR(<=) BOOL_OPERATOR(>=)
    BOOL_OPERATOR(==) BOOL_OPERATOR(!=)
    #undef BOOL_OPERATOR
};

bool CompRank(const int &x, const int &y){
    return Binary(rankA[x], rankB[x]) < Binary(rankA[y], rankB[y]);
}

void readfile(){
    freopen("RANKING.INP", "r", stdin);
    freopen("RANKING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> rankA[i];
    for(int i = 1; i <= n; i++) cin >> rankB[i];
    for(int i = 1; i <= n; i++) pos[i] = i;
    sort(pos + 1, pos + n + 1, CompRank);
}
bool checkBest(int x, int k){
    Binary best(rankA[x], rankB[x], 1);
    int j = n;
    for(int i = 1; i <= n - k; i++){
        if(pos[j] == x) j--;
        int tam = pos[j--];
        Binary bin(rankA[tam], rankB[tam], k + i);
        if(bin < best) return false;
    }
    return true;
}
int FindBest(int x){
    int l = 1, r = n;
    while(true){
        if(l == r) return l;
        if(r - l == 1) return checkBest(x, l) ? l : r;
        int m  = (l + r) >> 1;
        if(checkBest(x, m)) r = m;
        else l = m + 1;
    }
}
bool checkWorst(int x, int k){
    Binary worst(rankA[x], rankB[x], n);
    int j = 1;
    for(int i = 1; i <= k - 1; i++){
        if(pos[j] == x) j++;
        int tam = pos[j++];
        if(Binary(rankA[tam], rankB[tam], k - i) >= worst) return false;
    }
    return true;
}
int FindWorst(int x){
    int l = 1, r = n;
    while(true){
        if(l == r) return r;
        if(r - l == 1) return checkWorst(x, r) ? r : l;
        int m = (l + r) >> 1;
        if(checkWorst(x, m)) l = m;
        else r = m - 1;
    }
}
void xuli(){
    ///for(int i = 1; i <= n; i++) cout << pos[i] << " " << rankA[pos[i]] << " " << rankB[pos[i]] << '\n';
    for(int i = 1; i <= n; i++)
        cout << FindBest(i) << " " << FindWorst(i) << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
