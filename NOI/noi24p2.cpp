#include "bits/stdc++.h"
using namespace std;

using ll = long long;

vector<int> ask(vector<int> a, vector<int> b);

int richest(int N, int T, int S) {
	auto get_max= [&](span<int> cands, span<int> res) {
		if (cands.size() == 1) return cands[0];
		unordered_map<int,int> f;
		for (int x : res) f[x]++;
		for (auto [x, y] : f)
			if (y == (int)cands.size() - 1) return x;
	};

	vector<int> cands(from_range, views::iota(0, N));
	if (T == 1) {
		vector<int> a, b;
		for (int i = 0; i < (int)cands.size(); i++)
			for (int j = 0; j < i; j++)
				a.push_back(cands[i]), b.push_back(cands[j]);
		auto res = ask(a, b);
		return get_max(cands, res);
	}

	auto work = [&](int k) {
		int m = cands.size(), rem = m % k, gc = m / k + !!rem;
		if (k == 3 || k == 6) gc--;

		int small = m / gc, extra = m % gc;
		vector<span<int>> groups(gc);
		for (int i = 0, j = 0; i < gc; i++) {
			int gs = small + (i < extra);
			groups[i] = span(cands.begin() + j, gs);
			j += gs;
		}
		vector<int> a, b;
		for (auto &v : groups) {
			int t = v.size();
			for (int i = 0; i < t; i++)
				for (int j = 0; j < i; j++)
					a.push_back(v[i]), b.push_back(v[j]);
		}
		auto c = ask(a, b);
		vector<int> res(gc);
		for (int j = 0, i = 0; j < gc; j++) {
			int gs = groups[j].size();
			int sz = gs * (gs - 1) / 2;
			res[j] = get_max(groups[j], span(c).subspan(i, sz));
			i += sz;
		}
		swap(res, cands);
	};

	for (int k : {2, 2, 2, 2, 3, 6, 19, 183}) work(k);
	return cands[0];
}
