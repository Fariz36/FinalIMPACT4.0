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

	int cnt = 4;
	unsigned long long x = 18401055938125600000;
	for (int i = 3; i*i < x; i++) { 
		if (x % i == 0) {
			cnt += 2;
		}
	}

  cout << cnt << endl;
	if (sqrt(x) * sqrt(x) == x) {
		cnt--;
	}

	int ans = log10(x) * cnt;
	cout << ans+1 << endl;

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