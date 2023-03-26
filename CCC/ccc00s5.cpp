#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-2;
int n; pair<double, double> p[101];
vector<pair<double, double>> ans;
double sqr(double x){return x * x;}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lf %lf", &p[i].first, &p[i].second);
	for (double i = 0; i <= 1000; i = i + 0.01){
		vector<pair<double, double>> tmp; double mn = 1000000;
		for (int j = 0; j < n; j++){
			double d = sqr(p[j].second) + sqr(p[j].first - i);
			if (d < mn){
				mn = d; tmp.clear();
				tmp.push_back(p[j]);
			} else if (abs(d - mn) < eps) tmp.push_back(p[j]);
		}
		for (auto x : tmp) ans.push_back(x);
	}
	sort(ans.begin(), ans.end()); ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	for (auto x : ans) printf("The sheep at (%.2f, %.2f) might be eaten.\n", x.first, x.second);
}
