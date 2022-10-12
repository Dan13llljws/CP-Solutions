#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define pb push_back
const int mod = 1e9 + 7, base = 131;
int r, c, fac[2]; double dp[1600005][2];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<int> decode(int mask){
	vector<int> ret(r*c);
	for (int &x : ret) x = mask % 3, mask /= 3;
	return ret;
}
int encode(vector<int> &a){
	int ret = 0;
	for (int i = sz(a) - 1; i >= 0; i--)
		ret = ret * 3 + a[i];
	return ret;
}
double rec(int mask, bool turn){
	double &ret = dp[mask][turn];
	if (ret != -1.0) return ret;
	vector<int> state = decode(mask);
	vector<double> sol;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (state[i*c+j] != turn + 1) continue;
			for (int k = 0; k < 4; k++){
				int nx = i + dir[k][0], ny = j + dir[k][1];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || !state[nx*c+ny]) continue;
				vector<int> new_state = state;
				new_state[nx*c+ny] = turn + 1, new_state[i*c+j] = 0;
				sol.pb(1 - rec(encode(new_state), turn ^ 1));
			}
		}
	}
	sort(sol.rbegin(), sol.rend());
	ret = 0.0;
	int sol_cnt = min(fac[turn], sz(sol));
	for (int i = 0; i < sol_cnt; i++) ret += sol[i];
	if (sol_cnt) ret /= sol_cnt;
	return ret;
}
int main(){
	for (int i = 0; i < 1600005; i++) dp[i][0] = dp[i][1] = -1.0;
	scanf("%d%d", &r, &c); getchar();
	vector<int> state(r*c);
	for (int i = 0; i < r; i++, getchar())
		for (int j = 0; j < c; j++){
			char ch = getchar();
			if (ch == 'J') state[i*c+j] = 1;
			else if (ch == 'D') state[i*c+j] = 2;
		}
	scanf("%d%d", &fac[0], &fac[1]);
	printf("%.3lf\n", rec(encode(state), 0));
}

