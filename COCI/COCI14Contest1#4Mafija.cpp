#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MM = 5e5 + 5;
int N, ch[MM], in[MM], cnt; 
queue<int> q;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N);
	for (int i = 1; i <= N; i++) sc(ch[i]), in[ch[i]]++;
	for (int i = 1; i <= N; i++)
		if (!in[i]) q.push(i);
	while(!q.empty()){
		int p = q.front(); q.pop();
		cnt++; 
		if (in[ch[p]] > 0){
			if (--in[ch[ch[p]]] == 0) q.push(ch[ch[p]]);
			in[ch[p]] = 0;
		}
	}
	for (int i = 1; i <= N; i++){
		if (in[i]-- > 0){
			int t = 1, tmp = ch[i];
			while(tmp != i) in[tmp]--, tmp = ch[tmp], t++;
			cnt += t / 2;
		}
	}
	pr(cnt);
	return 0;
}


