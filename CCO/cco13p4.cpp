#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 4005, MN = 5e5 + 5;
int L, q, t, f, s, o[MN], r[MN], c[MN], a[MM][MM], bit[MM][MM];
void upd(int x, int y, int v){
    for (int i = x; i < MM; i += i & -i)
        for (int j = y; j < MM; j += j & -j)
            bit[i][j] += v;
}
int get(int x, int y){
    int ret = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            ret += bit[i][j];
    return ret;
}
int main(){
    L = re, q = re;
    for (int i = 0; i < q; i++){
        char ch = getchar();
        if (ch == 'E') o[i] = 0;
        else if (ch == 'L') o[i] = 1;
        else o[i] = 2;
        r[i] = re, c[i] = re;
        int nr = 1000 + r[i] - c[i], nc = r[i] + c[i] + 1000;
        if (r[i] <= L + 1000 && o[i] < 2) a[r[i]][c[i]] += o[i] ? -1 : 1, upd(nr, nc, o[i] ? -1 : 1);
        if (o[i] == 2){
            if (a[r[i]][c[i]] || a[r[i]][c[i] + 1]) puts("No");
            else printf("%d\n", get(nr, nc) + get(999 + r[i] - c[i], r[i] + c[i] + 1001));
        } 
    } f = 1e9, s = 1e9;
    for (int i = L + 1; i <= L + 1000; i++)
        for (int j = 1; j <= 1000; j++){
            if (a[i][j]) continue;
            int nr = 1000 + i - j, nc = 1000 + i + j, w = get(nr, nc);
            if (w < f) s = f, f = w;
            else if (w < s) s = w;
        }
    printf("%d\n", f + s);
}
