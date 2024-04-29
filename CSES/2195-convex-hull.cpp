#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T _x=0, T _y=0) : x(_x), y(_y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
using P = Point<ll>;
 
vector<P> ConvexHull(vector<P> &p, bool include_colinear = 0) {
	P p0 = *min_element(p.begin(), p.end());
	sort(p.begin(), p.end(), [&p0](const P &a, const P &b) {
		ll c = p0.cross(a, b);
		if (!c) return (a - p0).dist2() < (b - p0).dist2();
		return c > 0;
	});
	if (include_colinear) {
		int i = p.size() - 1;
		while(i >= 0 && p0.cross(p.back(), p[i]) == 0) i--;
		reverse(p.begin() + i + 1, p.end());
	}
	vector<P> st;
	for (P pt : p) {
		while(st.size() >= 2 && st[st.size() - 2].cross(st.back(), pt) < 0) st.pop_back();
		st.push_back(pt);
	}
	return st;
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<P> p(n);
	for (auto &pt : p) cin >> pt.x >> pt.y;
	auto hull = ConvexHull(p, 1);
	cout << hull.size() << '\n';
	for (auto [x, y] : hull) cout << x << ' ' << y << '\n';
}
