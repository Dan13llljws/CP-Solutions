#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, h[MM]; vector<int> ans[2];
bool solve(int st){
	for (int i = st; i < n; i++){
		if (h[i] - ans[0].back() == ans[0][1] - ans[0][0]) ans[0].push_back(h[i]);
		else ans[1].push_back(h[i]);
	}
	if (ans[1].empty()) ans[1].push_back(ans[0].back()), ans[0].pop_back();
	if (ans[1].size() < 3) return 1;
	while(ans[0].back() - ans[1].back() == ans[1][1] - ans[1][0]) ans[1].push_back(ans[0].back()), ans[0].pop_back();
	for (int i = ans[1].size() - 1; i > 1; i--)
		if (ans[1][i] - ans[1][i - 1] != ans[1][1] - ans[1][0]){
			if (ans[0].back() - ans[1][i - 1] == ans[1][1] - ans[1][0] && ans[1][i] - ans[0].back() == ans[1][1] - ans[1][0])
				ans[1].push_back(ans[0].back()), ans[0].pop_back();
			else return 0;
		}
	return 1;
}
void print(){
	if (ans[0].empty()) ans[0].push_back(ans[1].back()), ans[1].pop_back();
	sort(ans[1].begin(), ans[1].end());
	printf("%d\n", ans[0].size());
	for (int x : ans[0]) printf("%d ", x);
	printf("\n%d\n", ans[1].size());
	for (int x : ans[1]) printf("%d ", x);
	puts("");
}
int main(){
	n = re;
	for (int i = 0; i < n; i++) h[i] = re;
	sort(h, h + n);
	ans[0].push_back(h[0]), ans[0].push_back(h[1]);
	if (solve(2)){print(); return 0;}
	ans[0].clear(), ans[1].clear();
	ans[0].push_back(h[0]), ans[0].push_back(h[2]), ans[1].push_back(h[1]);	
	if (solve(3)){print(); return 0;}
	ans[0].clear(), ans[1].clear();
	ans[0].push_back(h[1]), ans[0].push_back(h[2]), ans[1].push_back(h[0]);	
	if (solve(3)){print(); return 0;}
	puts("-1");
}
