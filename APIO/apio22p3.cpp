#include <bits/stdc++.h>
using namespace std;

vector<int> construct_permutation(long long k){
    vector<int> res;
    int down = 0;
    for (int i = __lg(k) - 1; i >= 0; i--){
        if (k >> i & 1){
            if (i && (k >> (i - 1) & 1) && down > 1){
                int n = res.size() + 1;
                for (int &x : res)
                    if (x > 1) x++;
                res.push_back(n);
                res.push_back(n + 1);
                res.push_back(2);
                i--;
            } else {
                res.push_back(res.size());
                for (int &x : res) x++;
                res.push_back(0);
                down++;
            }
        } else res.push_back(res.size());
    }
    return res;
}
