#include "bits/stdc++.h"
using namespace std;

namespace atcoder {

namespace internal {

std::vector<int> sa_naive(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int l, int r) {
        if (l == r) return false;
        while (l < n && r < n) {
            if (s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n), rnk = s, tmp(n);
    std::iota(sa.begin(), sa.end(), 0);
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        std::swap(tmp, rnk);
    }
    return sa;
}

// SA-IS, linear-time suffix array construction
// Reference:
// G. Nong, S. Zhang, and W. H. Chan,
// Two Efficient Algorithms for Linear Time Suffix Array Construction
template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
    int n = int(s.size());
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (n < THRESHOLD_NAIVE) {
        return sa_naive(s);
    }
    if (n < THRESHOLD_DOUBLING) {
        return sa_doubling(s);
    }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const std::vector<int>& lms) {
        std::fill(sa.begin(), sa.end(), -1);
        std::vector<int> buf(upper + 1);
        std::copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };

    std::vector<int> lms_map(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms_map[i] = m++;
        }
    }
    std::vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.push_back(i);
        }
    }

    induce(lms);

    if (m) {
        std::vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for (int v : sa) {
            if (lms_map[v] != -1) sorted_lms.push_back(v);
        }
        std::vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = sorted_lms[i - 1], r = sorted_lms[i];
            int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
            int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) same = false;
            }
            if (!same) rec_upper++;
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
        }

        auto rec_sa =
            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

        for (int i = 0; i < m; i++) {
            sorted_lms[i] = lms[rec_sa[i]];
        }
        induce(sorted_lms);
    }
    return sa;
}

}  // namespace internal

std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
    assert(0 <= upper);
    for (int d : s) {
        assert(0 <= d && d <= upper);
    }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
    int n = int(s.size());
    std::vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    std::vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return internal::sa_is(s2, 255);
}

// Reference:
// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,
// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its
// Applications
template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
                           const std::vector<int>& sa) {
    assert(s.size() == sa.size());
    int n = int(s.size());
    assert(n >= 1);
    std::vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        assert(0 <= sa[i] && sa[i] < n);
        rnk[sa[i]] = i;
    }
    std::vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return lcp_array(s2, sa);
}

}  // namespace atcoder

template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
  // res[2 * i] = odd radius in position i
  // res[2 * i + 1] = even radius between positions i and i + 1
  // s = "abaa" -> res = {0, 0, 1, 0, 0, 1, 0}
  // in other words, for every z from 0 to 2 * n - 2:
  // calculate i = (z + 1) >> 1 and j = z >> 1
  // now there is a palindrome from i - res[z] to j + res[z]
  // (watch out for i > j and res[z] = 0)
}

template <typename T>
vector<int> manacher(const T &s) {
  return manacher((int) s.size(), s);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tests; cin >> tests >> tests;
	while(tests--) [&]() {
		int n, q; cin >> n >> q;
		string s; cin >> s;
		string t = s; reverse(t.begin(), t.end());
	for (int i = 0; i < n; i++) assert(s[i] == t[n-i-1]);
		string st = s + t;
		auto sa = atcoder::suffix_array(st);
		// count number of s[i...i+l-1] <= R(s[i+l...i+2l-1]) = t[n-i-2l...n-i-l-1]
		//                                 = st[2n-i-2l...2n-i-l-1]
		// from 2n-i-2 to 2n-i-2r
		vector<int> odd(2 * n + 1), even(2 * n + 1);
		auto upd = [&](vector<int> &bit, int x, int v) {
			for (++x; x <= 2 * n; x += x & -x) bit[x] += v;
		};
		auto get = [&](vector<int> &bit, int x) {
			int ret = 0;
			for (++x; x; x -= x & -x) ret += bit[x];
			return ret;
		};
		struct query{ int r, id; };
		vector<vector<query>> qs(n);
		for (int i = 0; i < q; i++) {
			int j, r; cin >> j >> r; --j;
			qs[j].emplace_back(r, i);
		}
		vector<int> ans(q);
		for (int i = 2 * n - 1; i >= 0; i--) {
			int j = sa[i];
			// dbg(j);
			if (j < n) {
				auto &bit = j & 1 ? odd : even;
				for (auto &[r, id] : qs[j]) {
					ans[id] = get(bit, 2 * n - j - 2) - get(bit, 2 * n - j - 2 * r - 1);
				}
			} else {
				auto &bit = j & 1 ? odd : even;
				upd(bit, j, 1);
			}
		}
        // subtract s[i...] == s[...i+2l-1] and s[i+2l...] < s[...i-1]
		auto pal = manacher(s);
        vector<int> rank(sa.size());
        for (int i = 0; i < 2 * n; i++) rank[sa[i]] = i;
        vector<vector<int>> f(n);
        auto cmp = [&](int i, int j) { // check if s[...i] > s[j...]
            if (i < 0) return false; // i = epsilon
            return rank[j] < rank[2 * n - i - 1];
        };
        struct event{ int t, x, y; }; // t=0 line end, t=1 line start
        vector<event> e;
        for (int i = 0; i < n - 1; i++) {
            int j = 2 * i + 1;
            // if (i - pal[j] + 1 == 8) dbg(j, pal[j], s.substr(i - pal[j] , 2 * pal[j] + 2));
            // add points(i, i+1), (i-1, i+2), ..., (i-pal[j]+1, i+pal[j])
            // becomes   (i, 2i+1), (i-1, 2i+1), ..., (i-pal[j]+1, 2i+1)
            if (pal[j] > 0 && cmp(i - pal[j], i + pal[j] + 1)) {
                e.emplace_back(1, i - pal[j] + 1, j);
                e.emplace_back(0, i + 1, j);
            }
        }
        sort(e.begin(), e.end(), [](auto a, auto b) {
            return a.x == b.x ? a.t < b.t : a.x < b.x;
        });
        vector<int> bit(2 * n + 1);
        for (int i = 0, j = 0; i < n; i++) {
            while(j < (int)e.size() && e[j].x <= i) {
                if (e[j].t == 0) upd(bit, e[j].y, 1);
                else upd(bit, e[j].y, -1);
                j++;
            }
            for (auto &[r, id] : qs[i]) {
                ans[id] += get(bit, 2 * (r + i) - 1);
            }
        }
		for (int i = 0; i < q; i++) cout << ans[i] << '\n';
	}();
}