#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e4 + 5;
int n, m, t, ans, st[MM], h[MM]; vector<int> v[MM];
int main(){
	n = re, m = re, t = re;
	while(t--){
		int x = re, y = re;
		v[x*2+1].push_back(y*2+1);
	}
	for (int i = 1; i <= 2*n+1; i++){
		for (int j = 1; j <= 2*m+1; j++) h[j]++;
		for (int x : v[i]) h[x] = 0;
		t = 0;
		for (int j = 1; j <= 2*m+2; st[++t] = j++)
			while(t && h[st[t]] >= h[j]) 
				ans = max(ans, ((h[st[t]]+((h[st[t]]&1)^(i&1)))/2)*((j-st[t-1]-1+((j-st[t-1]-1)&1&j))/2)), t--;
	}
	printf("%d\n", ans);
}

