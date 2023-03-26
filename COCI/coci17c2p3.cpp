#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define af(x) x.begin(), x.end()
const int mod = 1e9 + 7, MM = 5e5 + 5;
int n, mx, ansl, ansr, a[MM], psa[MM]; vector<int> f[MM*2];
int main(){
	n = re;
	for (int i = 1; i <= n; i++){
		a[i] = re, psa[i] += psa[i - 1];
		if (a[i] == i) psa[i]++;
		f[i+a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++){
		int l = i, r = a[i], mid = l + r;
		if (l > r) swap(l, r);
		int tmp = psa[l - 1] + psa[n] - psa[r];
		tmp += upper_bound(af(f[mid]), r) - lower_bound(af(f[mid]), l);
		if (tmp > mx) mx = tmp, ansl = l, ansr = r;
	}
	printf("%d %d\n", a[ansl], a[ansr]);
}

