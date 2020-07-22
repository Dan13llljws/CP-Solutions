#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e3 + 5;
int r, c, maxa, t, st[MM], g[MM][MM], h[MM];
int main(){
	r = re, c = re;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			g[i][j] = re;
	for (int i = 1; i < r; i++){
		for (int j = 1; j < c; j++)
			if (g[i][j] + g[i - 1][j - 1] <= g[i - 1][j] + g[i][j - 1]) h[j]++;
			else h[j] = 0;
		t = 0;
		for (int j = 1; j <= c; j++){
			while(t && h[st[t]] > h[j]) maxa = max(maxa, (h[st[t]] + 1) * (j - st[--t]));
			st[++t] = j;
		}
	}
	printf("%d", maxa);
}
