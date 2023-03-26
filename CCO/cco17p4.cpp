#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 505;
int n, sum, a[MM], dp[MM*50]; unordered_set<int> h;
int main(){
	n = re, dp[0] = 1;
	for (int i = 1; i <= n; i++) a[i] = re;
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++){
		for (int j = 50 * n; j; j--)
			for (int x : h) if (j >= x - a[i]) dp[j] |= dp[j - x + a[i]];
		if (i != 1) h.insert(a[i]);
	}
	for (int i = 0; i <= 50 * n; i++)
		if (dp[i]) printf("%d ", i);
}
