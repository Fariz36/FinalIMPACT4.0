#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

constexpr int mod = 1e9 + 7;

template<int MOD = mod>
struct Mint
{
    int val;

    Mint() : val(0) {}
    Mint(int64_t _val) : val((int)(_val % MOD)) { if (val < 0) val += MOD; }

    Mint& operator+= (const Mint &rhs) { val += rhs.val; if (val >= MOD) val -= MOD; return *this; }
    Mint& operator-= (const Mint &rhs) { val -= rhs.val; if (val < 0) val += MOD; return *this; }
    Mint& operator*= (const Mint &rhs) { val = (int)(1ll * val * rhs.val % MOD); return *this; }

    friend Mint fpow(Mint x, int64_t y)
    {
        Mint res = 1;
        for (; y > 0; y >>= 1, x *= x)
        {
            if (y & 1)
                res *= x;
        }
        return res;
    }
    friend Mint inverse(Mint x) { return fpow(x, MOD-2); }
    Mint& operator/= (const Mint &rhs) { return *this *= inverse(rhs); }

    friend Mint operator+ (Mint a, const Mint &b) { return a += b; }
    friend Mint operator- (Mint a, const Mint &b) { return a -= b; }
    friend Mint operator- (Mint a) { return 0 - a; }
    friend Mint operator* (Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/ (Mint a, const Mint &b) { return a /= b; }
    friend ostream& operator<< (ostream &os, const Mint &a) { return os << a.val; }
    friend bool operator== (const Mint &a, const Mint &b) { return a.val == b.val; }
    friend bool operator!= (const Mint &a, const Mint &b) { return a.val != b.val; }
};

const Mint<> div2 = 5e8 + 4;

Mint<> sum(Mint<> left, Mint<> right){
    return (right * (right + Mint<>(1)) * div2) - (left * (left - Mint<>(1)) * div2);
}

struct line{
    ll m, c;

    line(){
        m = 0; c = 2e18;
    }

    ld getInter(line &other){
        return (ld)(c - other.c) * 1.0 / (ld)(other.m - m);
    }

    line(ll _m, ll _c){
        m = _m; c = _c;
    }

    ll get_y(ll x){
        return m * x + c;
    }
};

bool cmp(line second_last, line last, line to_add){
    return to_add.getInter(second_last) >= to_add.getInter(last);
}

vector<pair<int, ll>> adj[2005];
bool vis[2005][2005];
ll dist[2005][2005];

void solve(){
    int N, M; ll X, L; cin >> N >> M >> X >> L;

    for(int i = 1; i <= M; ++i){
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= N + 3; ++j){
            dist[i][j] = 1e18;
        }
    }

    dist[1][0] = 0;
    for(int len = 0; len <= N; ++len){
        for(int i = 1; i <= N; ++i){
            for(pair<int, ll> nx : adj[i]){
                dist[nx.first][len + 1] = min(dist[nx.first][len + 1], dist[i][len] + nx.second);
            }
        }
    }

    if(X == 0){
        ll answer = 1e18;
        for(int i = 1; i < N; ++i){
            answer = min(answer, dist[N][i]);
        }
        cout << Mint<>(answer) * Mint<>(L + 1) << "\n";
        return;
    }

    vector<line> lines;
    for(int i = N - 1; i; --i){
        if(dist[N][i] >= 1e18){
            continue;
        }

        line cur = line((ll)i * X, dist[N][i]);
        while((int)lines.size() >= 2 && cmp(lines[(int)lines.size() - 2], lines.back(), cur)){
            lines.pop_back();
        }
        lines.push_back(cur);
    }

    int start = 0;
    for(; start < (int)lines.size() - 1; ++start){
        line cur = lines[start];
        if(cur.getInter(lines[start + 1]) >= 0){
            break;
        }
    }

    ll left = 0, right;
    Mint<> answer = 0;
    for(int i = start; i < (int)lines.size() - 1; ++i){
        line cur = lines[i];
        ll temp = (ll)cur.getInter(lines[i + 1]);

        right = min(temp, L);
        if(left > right)continue;

        answer += sum(left, right) * Mint<>(cur.m) + Mint<>(right - left + 1) * Mint<>(cur.c);

        left = right + 1;
        if(left > L)break;
    }

    if(left <= L){
        right = L;
        answer += sum(left, right) * Mint<>(lines.back().m) + Mint<>(right - left + 1) * Mint<>(lines.back().c);
    }

    cout << answer << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc = 1; //cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}
