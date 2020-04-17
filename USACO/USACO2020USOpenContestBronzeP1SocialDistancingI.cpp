#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
int n, ans;
string s, tmp;
pii get_gap(){
	int mx = 0, pos = 0, l = -1;
	for (int i = 0; i <= n + 1; i++){
		if (tmp[i] == '1'){
			if (l != -1 && mx < i - l){
				mx = i - l;
				pos = l;
			}
			l = i;
		}
	}
	return {mx, pos};
}
int get_ans(){
	int mn = n + 2, l = -1;
	for (int i = 1; i <= n; i++){
		if (tmp[i] == '1'){
			if (l != -1) mn = min(mn, i - l);
			l = i;
		}
	}
	return mn;
}
int main(){
	cin >> n >> s;
	s = "1" + s + "1"; tmp = s;
	pii p = get_gap();
	if (p.f >= 3){
		tmp[p.s + p.f / 3] = '1';
		tmp[p.s + p.f * 2 / 3] = '1';
		ans = max(ans, get_ans());
	}
	tmp = s;
	if (p.f >= 2){
		tmp[p.s + p.f / 2] = '1';
		p = get_gap();
		tmp[p.s + p.f / 2] = '1';
		ans = max(ans, get_ans());
	}
	tmp = s;
	if (tmp[1] == '0' && tmp[n] == '0'){
		tmp[1] = '1', tmp[n] = '1';
		ans = max(ans, get_ans());
	}
	tmp = s;
	if (tmp[1] == '0'){
		tmp[1] = '1';
		p = get_gap();
		tmp[p.s + p.f / 2] = '1';
		ans = max(ans, get_ans());
	}
	tmp = s;
	if (tmp[n] == '0'){
		tmp[n] = '1';
		p = get_gap();
		tmp[p.s + p.f / 2] = '1';
		ans = max(ans, get_ans());
	}
	cout << ans;
	return 0;
}
