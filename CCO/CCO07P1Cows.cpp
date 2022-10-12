#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define x first
#define y second
const int mod = 1e9 + 7, MM = 1e4 + 5;
int n, t, ans, st[MM]; pii p[MM];
int cross(pii a, pii b, pii c){return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);}
int main(){
	n = re;
	for (int i = 0; i < n; i++){
		p[i] = {re, re};
		if (p[i].y < p[0].y) swap(p[0], p[i]);
	} sort(p + 1, p + n, [&](pii a, pii b){
		double A = atan2(a.y - p[0].y, a.x - p[0].x), B = atan2(b.y - p[0].y, b.x - p[0].x);
		return A == B ? a.x < b.x : A < B;
	}); t = 1, p[n] = p[0];
	for (int i = 1; i <= n; st[++t] = i++)
		while(t > 1 && cross(p[st[t - 1]], p[st[t]], p[i]) <= 0) t--;
	for (int i = 1; i < t; i++)
		ans += (p[st[i + 1]].x + p[st[i]].x) * (p[st[i + 1]].y - p[st[i]].y);
	printf("%d\n", ans / 100);
}
