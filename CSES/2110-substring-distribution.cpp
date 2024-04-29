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

int main() {
	string s; cin >> s;
	sam.extend(s);
	int n = s.size();
	vector<int> ans(n + 2);
	for (int i = 0; i < sam.size; i++) {
		int par = sam.states[i].link;
		if (par != -1) {
			ans[sam.states[i].len + 1]--;
			ans[sam.states[par].len + 1]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		ans[i] += ans[i - 1];
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
