#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MM = 1e6 + 5;
int cnt[3], psa[MM][3], ans = INF;
char str[MM];
int main(){
	scanf("%s", str + 1);
	for (int i = 1; str[i]; i++){
		cnt[str[i] - 'A']++;
		psa[i][str[i] - 'A']++;
		for (int j = 0; j < 3; j++) psa[i][j] += psa[i - 1][j];
	}
	for (int i = 1; str[i]; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 3; k++){
				if (j == k || cnt[j] + cnt[k] > i) continue;
				int l = i - cnt[j] - cnt[k], m = i - cnt[k];
				int mis_l = cnt[j] - psa[m][j] + psa[l][j], mis_r = cnt[k] - psa[i][k] + psa[m][k];
				int mis_b = min(psa[m][k] - psa[l][k], psa[i][j] - psa[m][j]);
				ans = min(ans, mis_l + mis_r - mis_b);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
