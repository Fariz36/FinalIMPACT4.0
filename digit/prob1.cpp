#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define endl '\n'
#define sz(x) (int)x.size()

const int mod = 1e9+7;

void solve() {
	//count how much time needed
	time_t start, end;
	time(&start);

	double now = 0;
	for (int i = 1; i <= 1000; i++) {
		now += log10(i);
	} 
	cout << (int)now + 1 << endl;

	time(&end);
	double time_taken = double(end - start); 
		cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
		cout << " sec " << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc = 1;
  //cin >> tc;
  
  while (tc--) {
    solve();
  }
}