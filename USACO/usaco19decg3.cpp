#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, m, k, ans = INF, dist[26][26], psa[26][MM], dp[MM][26]; char s[MM];
int main(){
	n = re, m = re, k = re;
	scanf("%s", s + 1); ms(dp, inf); ms(dist, inf);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) 
			dist[i][j] = re;
	for (int i = 0; i < m; i++)
		for (int x = 0; x < m; x++)
			for (int y = 0; y < m; y++)
				dist[x][y] = min(dist[x][y], dist[x][i] + dist[i][y]);
	for (int i = 0; i < m; i++)
		for (int j = 1; j <= n; j++)
			psa[i][j] = dist[s[j] - 'a'][i] + psa[i][j - 1];
	for (int i = 0; i < m; i++) dp[k][i] = psa[i][k];
	for (int i = k + 1; i <= n; i++){
		int mdp = INF;
		for (int j = 0; j < m; j++)
			dp[i][j] = dp[i - 1][j] + dist[s[i] - 'a'][j], mdp = min(mdp, dp[i - k][j]);
		for (int j = 0; j < m; j++)
			dp[i][j] = min(dp[i][j], mdp + psa[j][i] - psa[j][i - k]);
	}
	for (int i = 0; i < m; i++) ans = min(ans, dp[n][i]);
	printf("%d", ans);
}
