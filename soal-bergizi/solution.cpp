#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll calc(ll N, ll p, ll q, ll r){

    if(p == 0){
        return ((q / r) & 1) & ((N + 1) & 1);
    }
    if(p >= r || q >= r){
        ll temp;
        if(N & 1){
            temp = (((N + 1) / 2) % 2) * (N % 2) % 2;
        }
        else{
            temp = ((N / 2) % 2) * ((N + 1) % 2) % 2;
        }
        return ((temp & ((p / r) & 1)) + (((q / r) & 1) & ((N + 1) & 1)) + calc(N, p % r, q % r, r)) & 1;
    }
    ll v = (p * N + q) / r;
    return ((((v & 1) * N) & 1) - calc(v - 1, r, r - q - 1, p)) & 1;
}

void solve(){
    ll N, p, q, r; cin >> N >> p >> q >> r;

    ll bound = (p * N + q) / r;

    ll answer = 0;
    for(int k = 0; k <= 60; ++k){
        if(bound < (1LL << k)){
            continue;
        }

        if(calc(N, p, q, r * (1LL << k))){
            answer += (1LL << k);
        }
    }

    cout << answer << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc = 1; cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}
