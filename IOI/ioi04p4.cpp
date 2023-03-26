#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int h, w, n, dp[605][605];
int main(){
	h = re, w = re, n = re; memset(dp, inf, sizeof dp); dp[1][1] = 1;
	while(n--) dp[re][re] = 0;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++){
			for (int i1 = 1; i1 <= i / 2; i1++) dp[i][j] = min(dp[i][j], dp[i1][j] + dp[i - i1][j]);
			for (int j1 = 1; j1 <= j / 2; j1++) dp[i][j] = min(dp[i][j], dp[i][j1] + dp[i][j - j1]);
		}
	printf("%d\n", dp[h][w]);
}

