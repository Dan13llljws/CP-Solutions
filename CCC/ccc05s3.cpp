#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define flood(x) ms(x, 0x3f)
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int M = 2048;
int n, a[M][M], b[M][M], R[M][M], r, c, repr, repc;
int maxx = -INF, minn = INF, maxr = -INF, minr = INF, maxc = -INF, minc = INF, row[M], col[M];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n);
    sc(r, c);
    repr = r, repc = c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            sc(a[i][j]);
        }
    }
    for (int T = 1; T < n; T++){
        sc(r, c);
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                sc(b[i][j]);
            }
        }
        for (int i = 0; i < repr; i++){
            for (int j = 0; j < repc; j++){
                for (int k = 0; k < r; k++){
                    for (int l = 0; l < c; l++){
                        R[k + i * r][l + j * c] = b[k][l] * a[i][j];
                    }
                }
            }
        }
        memcpy(a, R, sizeof R);
        repr *= r, repc *= c;
    }
    for (int i = 0; i < repr; i++){
        for (int j = 0; j < repc; j++){
            minn = min(minn, a[i][j]);
            maxx = max(maxx, a[i][j]);
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    for (int i = 0; i < repr; i++){
        maxr = max(maxr, row[i]);
        minr = min(minr, row[i]);
    }
    for (int i = 0; i < repc; i++){
        maxc = max(maxc, col[i]);
        minc = min(minc, col[i]);
    }
    pr(maxx, nl, minn, nl, maxr, nl, minr, nl, maxc, nl, minc);
    return 0;
}
