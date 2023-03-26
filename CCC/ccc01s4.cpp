#include <bits/stdc++.h>
using namespace std;
int n; double ans = 9999999; pair<int, int> p[10]; 
double sqr(double x){return x * x;}
pair<double, double> get_cent(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	double mx1, mx2, my1, my2;
	mx1 = (a.first + b.first) / 2.0, mx2 = (b.first + c.first) / 2.0;
	my1 = (a.second + b.second) / 2.0, my2 = (b.second + c.second) / 2.0;
	double a1 = b.second - a.second, b1 = a.first - b.first, c1 = a1 * a.first + b1 * a.second;
	double a2 = c.second - b.second, b2 = b.first - c.first, c2 = a2 * b.first + b2 * b.second;
	c1 = -b1 * mx1 + a1 * my1, c2 = -b2 * mx2 + a2 * my2;
	swap(a1, b1), swap(a2, b2); a1 = -a1, a2 = -a2;
	return {(b2 * c1 - b1 * c2) / (a1 * b2 - a2 * b1), (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1)};
}
bool check(pair<double, double> cent, double r){
	for (int i = 0; i < n; i++)
		if (sqr(cent.first - p[i].first) + sqr(cent.second - p[i].second) > r) return 0;
	return 1;
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i].first, &p[i].second);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			pair<double, double> cent = {(p[i].first + p[j].first) / 2.0, (p[i].second + p[j].second) / 2.0};
			double r = sqr(cent.first - p[i].first) + sqr(cent.second - p[i].second);
			if (check(cent, r)) ans = min(ans, r);
			for (int k = j + 1; k < n; k++){
				cent = get_cent(p[i], p[j], p[k]);
				r = sqr(cent.first - p[i].first) + sqr(cent.second + p[i].second);
				if (check(cent, r)) ans = min(ans, r);
			}
		}
	printf("%.2f", 2 * sqrt(ans));
}
