#include <bits/stdc++.h>
#include <chrono>
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
//#define endl '\n'
#define sz(x) (int)x.size()

const int mod = 1e9+7;

void solve() {
	int n, ans = 0;
	cin >> n;

	int arr[n+5], real[n+5];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		real[i] = arr[i];
	}

  auto start = chrono::high_resolution_clock::now();

	sort(arr+1, arr+n+1);
	
  int mx = arr[n];
  int sum2 = 2*arr[n] + 69;

	for (int bit = 0; bit <= 30; bit++) {
		int ada[sum2];
		int dp[sum2];
		int cnt = 0;

		int mod = (1<<(bit+1));
		memset(dp, 0, sizeof dp);
		memset(ada, 0, sizeof ada);

		for (int k = 1; k <= n; k++) {
			arr[k] = real[k];
			arr[k] = arr[k] % mod; 
			if (arr[k] == 0) arr[k] = mod;
		}

		for (int k = 1; k <= n; k++) {
			int l = (1<<bit);
			int r = ((1<<(bit+1)) - 1);

			while (r / arr[k] <= mod && (l + arr[k] - 1) / arr[k] <= sum2) {
        //cout << (l + arr[k] - 1) / arr[k] << " " << r / arr[k] << endl;
				for (int i = (l + arr[k] - 1) / arr[k]; i <= r / arr[k] && i <= sum2; i++) {
					cnt += dp[i];
				}

				l += mod;
				r += mod;
			}

			for (int i = 0; i <= mx; i++) {
				int x = (i + arr[k]) % mod;
				if (x == 0) x = mod;

				dp[x] += ada[i];
			}
			ada[arr[k]]++;
		}
		
		if (cnt % 2 == 1) {
			ans += (1<<bit);
		}
	}

	cout << ans << endl;

	auto end = chrono::high_resolution_clock::now();
 
    // Calculating total time taken by the program.
  double time_taken = 
  chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  //cout << "Time taken by program is : " << fixed 
  //      << time_taken << setprecision(9);
  //cout << " sec" << endl;
}

signed main() {
  freopen("randomdikit.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc = 1;
  //cin >> tc;
  
  while (tc--) {
    solve();
  }
}