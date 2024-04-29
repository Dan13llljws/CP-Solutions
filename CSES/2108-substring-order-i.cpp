#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
	struct State {
		int len, link;
		map<char,int> ch;
	};
	int size, last;
	vector<State> states;
	vector<long long> cnt;
	void extend(char c) {
		int cur = size++;
		states.push_back(State{states[last].len + 1, 0, map<char,int>()});
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
				for (;p != -1 && states[p].ch[c] == q; p = states[p].link) states[p].ch[c] = clone; 
				states[q].link = states[cur].link = clone;
			}
		}
		last = cur;
	}
	SuffixAutomaton(const string &s): size(1), last(0) {
		states.push_back(State{0, -1, map<char,int>()});
		for (char c : s) extend(c);
	}
	bool search(string &s) {
		int cur = 0;
		for (char c : s) {
			if (!states[cur].ch.count(c)) return 0;
			cur = states[cur].ch[c];
		}
		return 1;
	}
	long long dfs(int cur) {
		if (cnt[cur] != -1) return cnt[cur];
		cnt[cur] = 1;
		for (auto [c, v] : states[cur].ch) cnt[cur] += dfs(v);
		return cnt[cur];
	}
	string kth(long long k) {
		cnt.resize(states.size(), -1);
		dfs(0);
		string ans;
		for (int cur = 0; k;) {
			for (auto [c, v] : states[cur].ch) {
				if (cnt[v] < k) k -= cnt[v];
				else {
					ans.push_back(c), cur = v, k--;
					break;
				}
			}
		}
		return ans;
	}
};

int main() {
	string s; cin >> s;
	long long k; cin >> k;
	SuffixAutomaton sam(s);
	cout << sam.kth(k) << '\n';
}
