#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
const int MAX = 2e6 + 10;
int Sub, T, n;
bool cx[100][100];

struct Point {
    int x, y;

    Point(int _x, int _y){
        x = _x, y = _y;
    }

    bool operator < (const Point &p) const {
        return y == p.y ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return x == p.x && y == p.y;
    }

    bool operator != (const Point &p) const {
        return x != p.x || y != p.y;
    }

};
Point a[NM], b[NM];

Point NA(-INF, -INF);

struct Line {
	int a, b;
	long long c;

	Line(const Point &m, const Point &n) {
		a = m.y - n.y;
		b = n.x - m.x;
		c = -(1LL * a * m.x + 1LL * b * m.y);

		int t = __gcd(__gcd(Abs(a), Abs(b)), Abs(c));
		a /= t; b /= t; c /= t;
		if (a < 0 || (a == 0 && b < 0)) {
			a = -a; b = -b; c = -c;
		}
	}

	bool contain(const Point &p) const {
		return 1LL * a * p.x + 1LL * b * p.y + c == 0;
	}

	Point intersect(const Line &l) const {
		int a1 = a, b1 = b;
		long long c1 = -c;
		int a2 = l.a, b2 = l.b;
		long long c2 = -l.c;

		long long d = 1LL * a1 * b2 - 1LL * a2 * b1;
		long long dx = c1 * b2 - c2 * b1;
		long long dy = a1 * c2 - a2 * c1;

		if (d == 0) return NA;
		if (dx % d != 0 || dy % d != 0) return NA;
		return Point(dx / d, dy / d);
	}

	bool operator < (const Line &p) const {
        return a < p.a || (a == p.a && b < p.b) || (a == p.a && b == p.b && c < p.c);
    }
};

struct Segment {
	Point a, b;

	Segment(const Point &_a = Point(), const Point &_b = Point()) {
		a = _a; b = _b;
		if(b < a) swap(a, b);
	}

	bool contain(const Point &p) const {
		return Line(a, b).contain(p) && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
	}

	Point intersect(const Segment &s) const {
		Point p = Line(a, b).intersect(Line(s.a, s.b));
		if (p == NA) return NA;
		return contain(p) && s.contain(p) ? p : NA;
	}

	bool operator < (const Segment &P) const {
        return a == P.a ? b < P.b : a < P.a;
    }
};
Segment tree[NM];

bool cmp(const pair<Point, int> &a, const pair<Point, int> &b){
    return a.fi == b.fi ? a.se > b.se : a.fi < b.fi;
}

vector<Segment> joinSegments(const vector<Segment> &segments) {
    vector<pair<Point, int>> events;
	for (Segment s : segments) {
		if (s.b < s.a) swap(s.a, s.b);
		events.push_back(make_pair(s.a, 1));
		events.push_back(make_pair(s.b, -1));
	}
    sort(ALL(events), cmp);

    vector<Segment> result;
	Point start;
	int cnt = 0;
	for (auto e : events) {
		cnt += e.se;
		if (e.se == 1 && cnt == 1) start = e.fi;
		if (e.se == -1 && cnt == 0) result.push_back(Segment(start, e.fi);
	}
    return result;
}
vector<Segment> mergeSegment(const vector<Segment> &segments) {
	map<Line, vector<Segment>> lines;
    for (Segment s : segments) {
		Line l(s.a, s.b);
		lines[l].push_back(s);
	}

	vector<Segment> result;
	for (auto p : lines) {
		vector<Segment> tmp = joinSegment(p.second);
		for (Segment s : tmp) result.push_back(tmp);
	}
	return result;
}

void xuli(){
    vector<Segment> s;
    for(int i = 1; i <= n; i++) s.push_back({a, b});

    for(auto ans : mergeSegment(s)){
        int d = 0;

    }
}
int main()
{
    FastIO
    freopen("INTPOINT.INP", "r", stdin);
    freopen("INTPOINT.OUT", "w", stdout);
    cin >> Sub >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
        }
        xuli();
    }

    return 0;
}
