#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
	struct State {
		int len, link, cnt;
		unordered_map<char,int> ch;
		State(int _len = 0, int _link = -1, int _cnt = 0): len(_len), link(_link), cnt(_cnt) {}
	};
	int size, last;
	vector<State> states;
	void extend(char c) {
		int cur = size++;
		states.emplace_back(states[last].len + 1, 0, 1);
		int p = last;
		for (;p != -1 && !states[p].ch.count(c); p = states[p].link) states[p].ch[c] = cur;
		if (p == -1) states[cur].link = 0;
		else {
			int q = states[p].ch[c];
			if (states[q].len == states[p].len + 1) states[cur].link = q;
			else {
				int clone = size++;
				states.push_back(states[q]);
				states[clone].len = states[p].len + 1;
				states[clone].cnt = 0;
				for (;p != -1 && states[p].ch[c] == q; p = states[p].link) states[p].ch[c] = clone; 
				states[q].link = states[cur].link = clone;
			}
		}
		last = cur;
	}
	void extend(const string &s) { for (char c : s) extend(c); }
	SuffixAutomaton(): size(1), last(0) { states.emplace_back(); }
	SuffixAutomaton(const string &s): size(1), last(0) { states.emplace_back(), extend(s); }
	bool search(string &s) {
		int cur = 0;
		for (char c : s) {
			if (!states[cur].ch.count(c)) return 0;
			cur = states[cur].ch[c];
		}
		return 1;
	}
}sam;

vector<long long> cnt;
long long dfs(int cur) {
	if (cnt[cur] != -1) return cnt[cur];
	cnt[cur] = sam.states[cur].cnt;
	for (auto [c, v] : sam.states[cur].ch) cnt[cur] += dfs(v);
	return cnt[cur];
}

string kth(long long k) {
	cnt.resize(sam.size, -1);
	dfs(0);
	string ans;
	for (int cur = 0; k > 0;) {
		for (char c = 'a'; c <= 'z'; c++) {
			if (!sam.states[cur].ch.count(c)) continue;
			int v = sam.states[cur].ch[c];
			if (cnt[v] < k) k -= cnt[v];
			else {
				ans.push_back(c), cur = v, k -= sam.states[cur].cnt;
				break;
			}
		}
	}
	return ans;
}

int main() {
	string s; cin >> s;
	sam.extend(s);
	vector<pair<int,int>> p;
	for (int i = 0; i < sam.size; i++) 
		p.emplace_back(sam.states[i].len, i);
	sort(p.begin(), p.end(), greater<pair<int,int>>());
	for (auto [len, i] : p) 
		if (sam.states[i].link != -1)
			sam.states[sam.states[i].link].cnt += sam.states[i].cnt;
	sam.states[0].cnt = 1;
	long long k; cin >> k;
	cout << kth(k) << '\n';
}
