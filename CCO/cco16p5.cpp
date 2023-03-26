#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2005;
struct L{int x, l, r, t;};
int n, m, k, x[MM], y[MM], q, vis[MM]; ll ans; vector<int> cmp; vector<L> line;
int lb(int v){
	return lower_bound(cmp.begin(), cmp.end(), v) - cmp.begin() + 1;
}
void upd(int x1, int y1, int x2, int y2){
	psa[x1][y1]++, psa[x1][y2 + 1]--, psa[x2 + 1][y1]--, psa[x2 + 1][y2 + 1]++;
}
int main(){
	n = re, m = re, k = re; 
	for (int i = 0; i < k; i++) x[i] = re, y[i] = re;
	q = re;
	for (int i = 0; i < k; i++){
		int lx = x[i] - q, rx = x[i] + q, ly = y[i] - q, ry = y[i] + q;
		cmp.push_back(ly), cmp.push_back(ry), line.push_back({lx, ly, ry, 1}), line.push_back({rx, ly, ry, 0});
	} sort(cmp.begin(), cmp.end()), cmp.reisze(unique(cmp.begin(), cmp.end()) - cmp.begin());
	sort(line.begin(), line.end(), [](L a, L b){return a.x == b.x ? a.t > b.t : a.x < b.x;});
	for (L l : line){
		l.l = lb(l.l), l.r = lb(l.r);
		if (l.t){
			for (int i = l.l; i <= l.r; vis[i++]++)
				if (!vis[i])
	
}

