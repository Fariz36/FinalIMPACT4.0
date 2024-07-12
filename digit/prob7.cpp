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

const int N = 17072005;
int factor[N+5];

void solve() {
	//count how much time needed
	time_t start, end;
	time(&start);

  int n = 17072005;
	/*
	long double ans = 0;
	for (int i = 1; i <= n-1; i++) {
		for (int j = n; j >= 1; j -= i) {
			ans += log10(j);
		}
	} 
	cout << (int)ans + 1 << endl;
	*/

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			factor[j]++;
		}
	}

	factor[0] = n-1;
	long double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += factor[i]*log10(n-i);
	}
	cout << (int)ans + 1 << endl;
	

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