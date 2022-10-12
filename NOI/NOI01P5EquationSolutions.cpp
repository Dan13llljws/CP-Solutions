#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds; using namespace std;
// containers
typedef long long ll;typedef double db; typedef long double ld;
typedef pair<int,int> pii;typedef pair<ll,ll> pll;typedef pair<db,db> pdb;
typedef vector<int>vi;typedef vector<ll>vll;typedef vector<pii>vpi;typedef vector<pll>vpl; typedef vector<db>vdb;
typedef vector<vi>vvi;typedef vector<vll>vvl;typedef vector<vpi>vvpi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
#define tcT template<class T
#define tcTU tcT, class U
tcT>using vec=vector<T>;
tcT>using pq=priority_queue<T>;
tcT>using uset=unordered_set<T>;
tcTU>using umap=unordered_map<T,U>;
tcT,size_t SZ>using ar=array<T,SZ>;

// macros
#define siz(x) (int)x.size()
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ft front()
#define bk back()
#define bg begin()
#define f first
#define s second	
// function
#define fvoid function<void
#define fint function<int
#define fll function<ll

// rng
mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a,ll b){return uniform_int_distribution<ll>(a,b)(g1);}

// some debugging sht that i copied from 1000000007 diff places
tcT>void _dbg(const T& t){cerr<<t;}
tcT,class... U>void _dbg(const T& t, const U&... u){cerr<<t<<", ";_dbg(u...);}
template<class... T>void _dbg(const T&... t){_dbg(t...);cerr<<endl;}
void var_info(int line, string names){cerr<<"line("<<line<<") -> ["<<names<<"]: ";}
#define dbg(...) var_info(__LINE__,#__VA_ARGS__),_dbg(__VA_ARGS__),cerr<<endl

tcT> void rem_dup(vector<T> &v){sort(af(v));v.resize(unique(af(v))-v.begin());}
tcT> int rem_dup(T v[], int &sz){sort(v,v+sz);return sz=unique(v,v+sz)-v;}
tcT> bool ckmin(T &a,const T &b){return b<a?a=b,1:0;}
tcT> bool ckmax(T &a,const T &b){return b>a?a=b,1:0;}
int pcnt(ll x){return __builtin_popcountll(x);}
int lg2(ll x){return 63 - __builtin_clzll(x);}
#define MOD1 1e9+7;
#define MOD2 998244353;
const int mod=MOD1;
ll fpow(ll a,ll b,ll m=mod){ll ret=1;while(b){if(b&1)ret=ret*a%m;a=a*a%m,b>>=1;}return ret;}
ll minv(ll x){return x?fpow(x,mod-2):1;}
const int MM = 1e5 + 5;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vi x(k), y(k), w(k), id(k);
    iota(af(id), 0);
    for (int i = 0; i < k; i++){
        cin >> x[i] >> y[i] >> w[i];
    }
    sort(af(id), [&](int i, int j){
        return w[i] > w[j];
    });
    vi dpr(n + 1, -1), dpc(m + 1, -1), dp(k);
    queue<int> q;
    for (int i = 0; i < k; i++){
        int j = id[i];
        while(siz(q) && w[q.ft] > w[j]){
            int jj = q.ft;
            ckmax(dpr[x[jj]], dp[jj]), ckmax(dpc[y[jj]], dp[jj]);
            q.pop();
        }
        ckmax(dp[j], dpr[x[j]] + 1);
        ckmax(dp[j], dpc[y[j]] + 1);
        q.push(j);
    }
    for (int i= 0; i < k; i++) cout << dp[i] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tests = 1;
// 	cin >> tests;
	for (int i = 1; i <= tests; i++){
// 		cout << "Case #" << i << ": ";
		solve();
	}
}


