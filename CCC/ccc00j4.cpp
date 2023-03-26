#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, cmd; vector<int> stream;
int main(){
    n = re;
    for (int i = 0; i < n; i++) stream.push_back(re);
    while(1){
        cmd = re;
        if (cmd == 77) break;
        else if (cmd == 99){
            int l = re - 1, p = re;
            stream.insert(stream.begin() + l, stream[l] * p / 100.0);
            stream[l + 1] -= stream[l];
        } else {
            int l = re - 1;
            stream[l] += stream[l + 1];
            stream.erase(stream.begin() + l + 1);
        }
    }
    for (int i = 0; i < (int)stream.size(); i++) printf("%d ", stream[i]);
}
