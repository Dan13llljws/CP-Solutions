#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n, x[205], y[205], rnd[205], rnd2[205], ans;  unordered_set<ll> s; mt19937 ran;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i), rnd[i] = ran() % mod, rnd2[i] = ran() % mod;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++){
			ll cur =  0, cur2 = 0; int dx = abs(x[i] - x[j]), dy = abs(y[i] - y[j]);
			if (dx > dy){
				vector<int> v;
				for (int k = 0; k < n; k++){
					if (x[k] >= min(x[i], x[j]) && x[k] <= max(x[i], x[j]) && 
						max(abs(y[k] - y[i]), abs(y[k] - y[j])) <= dx) v.push_back(k);
				}
				sort(v.begin(), v.end(), [](int a, int b){return y[a] < y[b];});
				int l = 0, r = 0;
				for (r = 0; r < (int)v.size() && y[v[r]] <= max(y[i], y[j]); r++)
					cur = (cur + rnd[v[r]]) % mod, cur2 = (cur2 + rnd2[v[r]]) % mod;
				s.insert(cur<<32|cur2);
				for (int k = r; k < (int)v.size(); k++){
					while(y[v[k]] - y[v[l]] > dx){
						cur = (cur - rnd[v[l]] + mod) % mod, cur2 = (cur2 - rnd2[v[l]] + mod) % mod;
						if (y[v[l]] + dx + 1 < y[v[k]]) s.insert(cur<<32|cur2);
						l++;
					}
					cur = (cur + rnd[v[k]]) % mod, cur2 = (cur2 + rnd2[v[k]]) % mod;
					s.insert(cur<<32|cur2);
				}
				while(l < (int)v.size() && y[v[l]] != min(y[i], y[j]))
					cur = (cur - rnd[v[l]] + mod) % mod, cur2 = (cur2 - rnd[v[l]] + mod) % mod, s.insert(cur<<32|cur2), l++;
				
			} else {
				vector<int> v;
				for (int k = 0; k < n; k++){
					if (y[k] >= min(y[i], y[j]) && y[k] <= max(y[i], y[j]) && 
						max(abs(x[k] - x[i]), abs(x[k] - x[j])) <= dy) v.push_back(k);
				}
				sort(v.begin(), v.end(), [](int a, int b){return x[a] < x[b];});
				int l = 0, r = 0;
				for (r = 0; r < (int)v.size() && x[v[r]] <= max(x[i], x[j]); r++) cur = (cur + rnd[v[r]]) % mod, cur2 = (cur2 + rnd2[v[r]]) % mod;
				s.insert(cur<<32|cur2);
				for (int k = r; k < (int)v.size(); k++){
					while(x[v[k]] - x[v[l]] > dy){
						cur = (cur - rnd[v[l]] + mod) % mod, cur2 = (cur2 - rnd2[v[l]] + mod) % mod;
						if (x[v[l]] + dy + 1 < x[v[k]]) s.insert(cur<<32|cur2);
						l++;
					}
					cur = (cur + rnd[v[k]]) % mod, cur2 = (cur2 + rnd2[v[k]]) % mod;
					s.insert(cur<<32|cur2);
				}
				while(l < (int)v.size() && x[v[l]] != min(x[i], x[j]))
					cur = (cur - rnd[v[l]] + mod) % mod, cur2 = (cur2 - rnd2[v[l]] + mod) % mod, s.insert(cur<<32|cur2), l++;
			}
		}
	printf("%d\n", s.size() + 1);
}
