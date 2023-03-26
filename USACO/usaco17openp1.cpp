#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1005;
int n, ans, cnt, g[MM][MM], b[4][MM*MM], psa[MM][MM], out[MM*MM];
int main(){
	n = re; memset(b[0], 0x3f, sizeof b[0]); memset(b[3], 0x3f, sizeof b[3]);
	for (int i = 1; i <= n; i++)	
		for (int j = 1; j <= n; j++){
			g[i][j] = re;
			if (!g[i][j]) continue;
			b[0][g[i][j]] = min(b[0][g[i][j]], i);
			b[1][g[i][j]] = max(b[1][g[i][j]], j);
			b[2][g[i][j]] = max(b[2][g[i][j]], i);
			b[3][g[i][j]] = min(b[3][g[i][j]], j);
		}
	for (int i = 1; i <= n * n; i++){
		if (b[0][i] == INF) continue;
		cnt++;
		psa[b[0][i]][b[3][i]]++, psa[b[0][i]][b[1][i] + 1]--, psa[b[2][i] + 1][b[3][i]]--, psa[b[2][i] + 1][b[1][i] + 1]++;
	}
	if (cnt == 1) return 0 * printf("%d\n", n * n - 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
			if (psa[i][j] > 1) out[g[i][j]]++;
		}
	for (int i = 1; i <= n * n; i++) ans += !out[i];
	printf("%d\n", ans);
}
