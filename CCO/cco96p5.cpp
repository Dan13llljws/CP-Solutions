#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb push_back
#define nl '\n'
char _;
typedef pair<int, int> pii;
typedef long long ll;
int n, m, vis[30];
vector<int> tree[30];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string str1, str2; cin >> str1 >> str2;
        tree[str1[0] - 'A'].pb(str2[0] - 'A');
        tree[str2[0] - 'A'].pb(str1[0] - 'A');
    }
    for (int i = 0; i < m; i++){
        string a1, a2, ans = ""; cin >> a1 >> a2;
        int st = a1[0] - 'A', ed = a2[0] - 'A';
        ms(vis, 0);
        stack<int> roads;
        roads.push(st); vis[st] = 1;
        while(!roads.empty()){
            int p = roads.top();
            if (p == ed){
                break;
            }
            for (int u : tree[p]){
                if (!vis[u]){
                    vis[u] = 1;
                    roads.push(u);
                    break;
                }
            }
            if (roads.top() == p) roads.pop();
        }
        while(!roads.empty()){
            ans = (char)(roads.top() + 'A') + ans;
            roads.pop();
        }
        cout << ans <<nl;
    }
    return 0;
}