#include <bits/stdc++.h>
using namespace std;

template<class T>
class ImplicitTreap {
public:
	struct Node {
		T key;
		int priority, size;
		Node *l, *r;
		Node(T _key): key(_key), priority(rand()), size(1), l(NULL), r(NULL) {}
	};
	Node *root;
	int get_size(Node *t) { return t ? t->size : 0; }
	void push_up(Node *t) { t->size = get_size(t->l) + get_size(t->r) + 1; }
	pair<Node*, Node*> split_by_key(Node *t, T key) { // split (-infty, key), [key, infty)
		if (!t) return {};
		if (t->key < key) {
			auto p = split_by_key(t->r, key);
			t->r = p.first;
			push_up(t);
			return {t, p.second};
		} else {
			auto p = split_by_key(t->l, key);
			t->l = p.second;
			push_up(t);
			return {p.first, t};
		}
	}
	pair<Node*, Node*> split_by_size(Node *t, int k) { // split [0...k), [k ... n)
		if (!t) return {};
		if (get_size(t->l) < k) {
			auto p = split_by_size(t->r, k - 1 - get_size(t->l));
			t->r = p.first;
			push_up(t);
			return {t, p.second};
		} else {
			auto p = split_by_size(t->l, k);
			t->l = p.second;
			push_up(t);
			return {p.first, t};
		}
	}
	Node* merge(Node *l, Node *r) {
		if (!l || !r) return l ? l : r;
		if (l->priority > r->priority) {
			l->r = merge(l->r, r);
			push_up(l);
			return l;
		} else {
			r->l = merge(l, r->l);
			push_up(r);
			return r;
		}
	}
	void heapify(Node *t) {
		if (!t) return;
		Node* max_ch = t;
		if (t->l != NULL && t->l->priority > max_ch->priority) max_ch = t->l;
		if (t->r != NULL && t->r->priority > max_ch->priority) max_ch = t->r;
		if (max_ch != t) swap(t->priority, max_ch->priority), heapify(max_ch);
	}
	Node* build(vector<T> &a, int l, int r) {
		if (l == r) return NULL;
		int mid = (l + r) >> 1;
		Node* t = new Node(a[mid]);
		t->l = build(a, l, mid);
		t->r = build(a, mid + 1, r);
		heapify(t);
		push_up(t);
		return t;
	}
	Node* ins(Node* t, Node* n, int pos) {
		auto p = split_by_size(t, pos);
		return merge(merge(p.first, n), p.second);
	}
	void move(Node*& t, int l, int r, int k) { // move [l, r) to index k
		Node *a, *b, *c;
		tie(a,b) = split_by_size(t, l); tie(b,c) = split_by_size(b, r - l);
		if (k <= l) t = merge(ins(a, b, k), c);
		else t = merge(a, ins(c, b, k - r));
	} 
	void move(int l, int r, int k) { move(root, l, r, k); }
	template<class F> 
	void flat(Node *r, F f) {
		if (r) { flat(r->l, f), f(r->key), flat(r->r, f); }
	}
	template<class F> void flat(F f) { flat(root, f); }
	ImplicitTreap(): root(NULL) {}
	ImplicitTreap(vector<T> &a): root(NULL) { root = build(a, 0, (int)a.size()); }
};
using ITreap = ImplicitTreap<char>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	string s; cin >> s; vector<char> ss(n);
	for (int i = 0; i < n; i++) ss[i] = s[i];
	ITreap treap(ss);
	while(m--) {
		int a, b; cin >> a >> b; a--, b--;
		treap.move(a, b + 1, n);		
	}
	treap.flat([&](char a) { cout << a; });	
}
