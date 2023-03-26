#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1005;
int n, m, a, b, c, d, ax, ay, ans, g[MM][MM], tmp[MM][MM], q[MM]; pair<int,int> mn[MM][MM];
int get(int x1, int y1, int x2, int y2){
    return g[x2][y2] - g[x1][y2] - g[x2][y1] + g[x1][y1];
}
int main(){
    m = re, n = re, b = re, a = re, d = re, c = re; 
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            g[i][j] = re + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
    for (int i = c; i <= n; i++){
        int l = 1, r = 0;
        for (int j = d; j <= m; j++){
            while(l <= r && j - q[l] > b - d - 2) l++;
            while(l <= r && get(i, j, i - c, j - d) <= get(i, q[r], i - c, q[r] - d)) r--;
            q[++r] = j, tmp[i][j] = q[l];
        }
    }
    for (int j = d; j <= m; j++){
        int l = 1, r = 0;
        for (int i = c; i <= n; i++){
            while(l <= r && i - q[l] > a - c - 2) l++;
            while(l <= r && get(i, tmp[i][j], i - c, tmp[i][j] - d) <=
                get(q[r], tmp[q[r]][j], q[r] - c, tmp[q[r]][j] - d)) r--;
            q[++r] = i, mn[i][j] = {q[l], tmp[q[l]][j]};
        }
    }
    for (int i = a; i <= n; i++)
        for (int j = b; j <= m; j++){
            int x = mn[i - 1][j - 1].first, y = mn[i - 1][j - 1].second;
            int cur = get(i, j, i - a, j - b) - get(x, y, x - c, y - d);
            if (cur > ans) ans = cur, ax = i, ay = j;
        }
    printf("%d %d\n%d %d\n", ay - b + 1, ax - a + 1, 
        mn[ax - 1][ay - 1].second - d + 1, mn[ax - 1][ay - 1].first - c + 1);
}
