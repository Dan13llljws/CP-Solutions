#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first 
#define y second
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 4010; 
int n, tot, w[MM], ans; pii p[MM];
ll cross(pii a, pii b, pii c){
	return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}
ll dis(pii a, pii b){
	return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}
int main(){
	n = re;
	for (int i = 0; i < n; i++) p[i] = {re, re}, tot += w[i] = re;
	for (int i = 0; i < n; i++){
		vector<int> v; int sum = w[i];
		for (int j = 0; j < n; j++) 
			if (j ^ i) v.push_back(j);
		if (n > 200) sort(v.begin(), v.end(), [&](int a, int b){
			ll t = cross(p[i], p[a], p[b]);
			if (t) return t > 0;
			return dis(p[a], p[i]) < dis(p[b], p[i]);
		});
		else sort(v.begin(), v.end(), [&](int a, int b){
			double A=atan2(p[a].y-p[i].y,p[a].x-p[i].x),B=atan2(p[b].y-p[i].y,p[b].x-p[i].x);
			return fabs(A-B)<1e-6 ? dis(p[a], p[i]) < dis(p[b], p[i]) : A < B;
		});
		for (int j = 0; j < n - 1; j++) v.push_back(v[j]);
		for (int j = 0, k = 0; j < (int)v.size(); j++){
			sum += w[v[j]];
			while(j - k >= n - 1 || (k < j && cross(p[i], p[v[k]], p[v[j]]) < 0)) sum -= w[v[k++]];
			if(k) ans = max({ans, sum, tot - sum});
		}
	} printf("%d\n", ans);
}
