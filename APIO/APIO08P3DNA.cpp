#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 5e4 + 5;
unordered_map<char, int> go = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
char go_back[5] = {'N', 'A', 'C', 'G', 'T'}, s[MM];
int M, K; ll R, dp[MM][5][10];
int main(){
	scanf("%d %d %lld %s", &M, &K, &R, s + 1); 
	dp[M + 1][4][0] = 1;
	for (int i = M; i; i--){
		int cur = go[s[i]];
		if (cur){
			for (int j = 1; j <= 4; j++)
				for (int k = (j < cur); k < K; k++)
					dp[i][cur][k] += dp[i + 1][j][k - (j < cur)];
		} else {
			for (int j = 1; j <= 4; j++)
				for (int j1 = 1; j1 <= 4; j1++)
					for (int k = (j1 < j); k < K; k++)
						dp[i][j][k] += dp[i + 1][j1][k - (j1 < j)];
		}
	}
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k < K; k++)
				dp[i][j][k] += dp[i][j][k - 1];
	int pre = 1; K--;
	for (int i = 1; i <= M; i++){
		K--;
		for (int j = 1; j <= 4; j++){
			if (j == pre) K++;
			if (dp[i][j][K] >= R){
				putchar(go_back[j]);
				pre = j; break;
			}
			R -= dp[i][j][K];
		}
	}
}

