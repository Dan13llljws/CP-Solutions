#include "bits/stdc++.h"
using namespace std;

void move_inside(int i);
void move_outside(int i);
int press_button();

int min_cardinality(int N) {
  unordered_set<int> in;
  for (int i = 0; i < N; i++) {
    move_inside(i);
    if (press_button() > 1) move_outside(i);
    else in.insert(i);
  }
  int k = in.size();
  vector<int> ban(N);
  int l = 1, r = N / k;
  while(l < r) {
    int mid = (l + r + 1) / 2;
    vector<int> added;
    for (int i = N - 1; i >= 0 && (int)in.size() < k * mid; i--) {
      if (ban[i] || in.count(i)) continue;
      move_inside(i);
      if (press_button() > mid) move_outside(i);
      else added.push_back(i), in.insert(i);
    }
    int s = in.size();
    if (s != k * mid) {
      for (int i = 0; i < N; i++)
        if (!in.count(i)) ban[i] = 1;
      for (int i : added) move_outside(i), in.erase(i);
      r = mid - 1;
    } else l = mid;
  }
  return l;
}