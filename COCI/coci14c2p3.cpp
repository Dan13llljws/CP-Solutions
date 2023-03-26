#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, k, ans, a[5005], dp[5005]; pair<int, int> v[5005];
int main(){
	n = re, k = re;
	for (int i = 0; i < n; i++) a[i] = re, v[i] = {a[i], i};
	sort(v, v + n);
	for (int i = 0; i < n; i++) a[v[i].second] = i / k;
	for (int i = 0; i < n; i++)
		if (a[i] >= dp[ans]) dp[++ans] = a[i];
		else dp[upper_bound(dp + 1, dp + ans + 1, a[i]) - dp] = a[i];
	printf("%d", n - ans);
}

