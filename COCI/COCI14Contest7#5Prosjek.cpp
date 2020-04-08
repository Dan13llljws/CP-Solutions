#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MM = 3e5 + 5;
int n, k, a[MM];
double psa[MM];
bool check(double x){
	for (int i = 1; i <= n; i++) psa[i] = psa[i - 1] + a[i] - x;
	double minv = 0;
	for (int i = 0, j = k; j <= n; i++, j++){
		minv = min(minv, psa[i]);
		if (psa[j] >= minv) return 1;
	}
	return 0;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(n, k);
	for (int i = 1; i <= n; i++) sc(a[i]);
	double l = 0, r = 1000000;
	while(r - l > 1e-5){
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.5f", r);
	return 0;
}

