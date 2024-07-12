#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int mod = 1e9+7;

struct Point{
  int x, y, idx;
};

struct seg {
  int stx, sty, enx, eny;
  int id1, id2;
  long double angle;
};

int n, k;
Point arr[369];
ii dp[369][369][10];

bool comp(seg a, seg b) {
    return a.angle < b.angle;
}

signed main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
    arr[i].idx = i;
  }

  vector<seg> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n ; j++) {
        if (i == j) continue;
        v.push_back({0, 0, 0, 0});
        int sz = v.size();
        v[sz-1].stx = arr[i].x;
        v[sz-1].sty = arr[i].y;
        v[sz-1].enx = arr[j].x;
        v[sz-1].eny = arr[j].y;
        v[sz-1].id1 = i;
        v[sz-1].id2 = j;
        v[sz-1].angle = atan2(arr[j].y - arr[i].y, arr[j].x - arr[i].x);
    }
  }
  
  int sz = v.size();
  sort(v.begin(), v.end(), comp);

  for (int i = 0; i < sz; i++) {
    int str = v[i].id1;
    int fin = v[i].id2;
    int a = v[i].stx, b = v[i].sty, c = v[i].enx, d = v[i].eny;

    int inc = a*d - b*c;
    inc %= mod;
    dp[str][fin][1].fi = 1;
    dp[str][fin][1].se = inc;

    for (int x = 2; x <= k; x++) {
        for (int j = 0; j < n; j++) {
            dp[j][fin][x].fi += dp[j][str][x-1].fi;
            dp[j][fin][x].fi %= mod;

            dp[j][fin][x].se += dp[j][str][x-1].se + dp[j][str][x-1].fi * (inc);
            dp[j][fin][x].se %= mod;
        }
    }
  }

  int ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    sum += dp[i][i][k].se;
    sum %= mod;
    sum += mod;
    sum %= mod;
  }
  cout << sum << endl;
}
