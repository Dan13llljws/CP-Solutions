#include <stdio.h>
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e5 + 5;
int n, m, tot, cnt, a[MM], bit[MM]; 
void upd(int x, int v){
    for (x++; x < MM; x += x & -x) bit[x] += v;
}
int lower_bound(int sum){
    int pos = 0;
    for (int pw = 1 << 17; pw; pw >>= 1)
        if (pos + pw < MM && sum > bit[pos + pw])
            sum -= bit[pos += pw];
    return pos;
}
int main(){
    n = re, m = re; 
    while(n--){
        char o; scanf(" %c ", &o); int x = re;
        if (o == 'I'){
            if (x >= m) upd(x, 1), a[x]++, cnt++;
        } else if (o == 'A'){
            for (int i = MM - 2; i - x >= 0; i--) upd(i, -a[i]), upd(i, a[i] = a[i - x]);
            for (int i = x - 1; i >= 0; i--) upd(i, -a[i]), a[i] = 0;
        } else if (o == 'S'){
            for (int i = 0; i < m + x && i < MM - 1; i++) tot += a[i], cnt -= a[i], upd(i, -a[i]), a[i] = 0;
            for (int i = 0; i + x < MM - 1; i++) upd(i, -a[i]), upd(i, a[i] = a[i + x]);
            for (int i = MM - x - 1; i < MM - 1; i++) upd(i, -a[i]), a[i] = 0;
        } else printf("%d\n", x > cnt ? -1 : lower_bound(cnt - x + 1));
    } printf("%d\n", tot);
}
