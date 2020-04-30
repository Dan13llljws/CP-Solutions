#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define sz(x) (int)(x.size())
const int mod = 1e9 + 7, base = 131, MM = 2e5 + 5;
int N, M, k[MM], B[MM], C[MM], L[MM], id[MM]; ll tot[MM], ans;
priority_queue<int> q[MM];
int main(){
	N = re, M = re;
	for (int i = 1; i <= N; i++) B[i] = re, C[i] = re, L[i] = re, id[i] = i, q[i].push(C[i]), tot[i] = C[i], k[i] = 1;
	for (int i = N; i; i--){
		while(tot[i] > M) tot[i] -= q[id[i]].top(), q[id[i]].pop(), k[i]--;
		ans = max(ans, 1LL * L[i] * k[i]);
		tot[B[i]] += tot[i], k[B[i]] += k[i];
		if (sz(q[id[i]]) > sz(q[id[B[i]]])) swap(id[i], id[B[i]]);
		while(!q[id[i]].empty()) q[id[B[i]]].push(q[id[i]].top()), q[id[i]].pop();
	}
	pr(ans);
	return 0;
}

