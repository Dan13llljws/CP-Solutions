#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e6 + 5;
int n, x, a2, a[MM], lmx[MM], mx[MM], q[MM]; long long a1;
int main(){
	n = re, x = re;
	for (int i = 0; i < n; i++) a[i] = re;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++){
		while(l <= r && q[l] < i - x + 1) l++;	
		while(l <= r && a[q[r]] >= a[i]) r--;
		q[++r] = i, lmx[i] = a[q[l]];
	}
	for (int i = 0; i <= n - x; i++) lmx[i] = lmx[i + x - 1];
	for (int i = n - x + 1; i < n; i++) lmx[i] = 0;
	l = 0, r = 0;
	for (int i = 0; i < n; i++){
		while(l <= r && q[l] < i - x + 1) l++;
		while(l <= r && lmx[q[r]] <= lmx[i]) r--;
		q[++r] = i, mx[i] = lmx[q[l]];
	}
	for (int i = 0; i < n; i++) a1 += a[i] - mx[i];
	int last = -1, curh = -1;
	for (int i = 0; i < n; i++)
		if (last < i || curh != mx[i])
			last = i + x - 1, curh = mx[i], a2++;
	printf("%lld\n%d\n", a1, a2);
}
