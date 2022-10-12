#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f; const char sp=' ',nl='\n';
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
const int mod = 1e9 + 7, base = 131, MM = 1e6 + 5;
struct fhqTreap{
	int l[MM], r[MM], val[MM], id[MM], rnd[MM], sz[MM], rt, tot, tx, ty, tz;
	int Rand(){
		static int seed = 703;
		return seed = int(seed * 48271LL % 2147483647);
	}
	int new_node(int v, int d){sz[++tot] = 1, id[tot] = d, val[tot] = v, rnd[tot] = Rand(); return tot;}
	int siz(int i){return i ? sz[i] : 0;}
	void update(int i){sz[i] = 1 + siz(l[i]) + siz(r[i]);}
	void split_by_val(int t, int k, int &a, int &b){
		if (!t) a = b = 0;
		else if (val[t] < k) b = t, split_by_val(l[t], k, a, l[t]);
		else a = t, split_by_val(r[t], k, r[t], b);
		update(t);
	}
	int merge(int a, int b){
		if (!a || !b) return a + b;
		else if (rnd[a] < rnd[b]){r[a] = merge(r[a], b), update(a); return a;}
		else {l[b] = merge(a, l[b]), update(b); return b;}
	}
	void insert(int v, int d){
		split_by_val(rt, v, tx, ty); 
		rt = merge(merge(tx, new_node(v, d)), ty);
	}
	void erase(int v){
		split_by_val(rt, v, tx, tz); split_by_val(tx, v + 1, tx, ty);
		ty = merge(l[ty], r[ty]), rt = merge(merge(tx, ty), tz);
	}
	int kth(int t, int k){
		while(1){
			if (k <= siz(l[t])) t = l[t];
			else if (k == siz(l[t]) + 1) return id[t];
			else k -= siz(l[t]) + 1, t = r[t];
		}
	}
}s;
int N, a[MM];
int main(){
	N = re;
	while(N--){
		char cmd = getchar();
		if (cmd == 'N'){
			int x = re, r = re;
			s.insert(r, x);
			a[x] = r;
		} else if (cmd == 'M'){
			int x = re, r = re;
			s.erase(a[x]); s.insert(r, x);
			a[x] = r;
		} else {
			int k = re;
			pr(s.kth(s.rt, k), nl);
		}
	}
	return 0;
}
