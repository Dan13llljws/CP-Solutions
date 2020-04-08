#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ipi;
const int MM = 1e5 + 5;
struct score{int s, rk, t;}scores[MM];
int t; double ans;
ll bit[MM];
void upd(int pos){
	for (; pos <= t; pos += pos & -pos)  bit[pos]++;
}
ll sum(int pos){
	int sum = 0;
	for (; pos > 0; pos -= pos & -pos) sum += bit[pos];
	return sum;
}
bool cmp1(score a, score b){
	if (a.s == b.s) return a.t > b.t;
	return a.s > b.s;
}
bool cmp2(score a, score b){return a.t < b.t;}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(t);
    for (int i = 0; i < t; i++){
		sc(scores[i].s);
		scores[i].t = i;
	}
	sort(scores, scores + t, cmp1);
	for (int i = 0; i < t; i++) scores[i].rk = i + 1;
	sort(scores, scores + t, cmp2);
	for (int i = 0; i < t; i++){
		upd(scores[i].rk);
		ans += sum(scores[i].rk);
	}
	printf("%.2f", ans / t);
    return 0;
}
