#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
int n, k, a[101]; bool dp[100005];
int main(){
	n = read(), k = read(); 
	for (int i = 0; i < n; i++) a[i] = read();
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (i >= a[j] && !dp[i - a[j]]) dp[i] = 1;
	puts(dp[k] ? "First" : "Second");
}
