#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, b, ans = 1e12;

void relax(ll u, ll v, ll k) {
    if (u * v != k) return;
    a = (v - u) / 2;
    b = (v + u) / 2;
    if (a >= 0 && b >= 0 && b < ans) {
        ans = b;
    }
}

int main() {
//    freopen("input.in", "r", stdin);
//    freopen("output.in", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll k;
    cin >> k;
    if (abs(k) % 4 == 2) {
        cout << "none";
        return 0;
    }
    if (k == 0) {
        cout << 0;
        return 0;
    }
    for (ll u = 1 ; u * u <= abs(k) ; ++u) {
        if (k % u == 0) {
            ll v = abs(k) / u;
            if (u % 2 == v % 2) {
                for (int i = 0 ; i < 8 ; ++i) {
                    relax(u, v, k);
                    relax(u, -v, k);
                    relax(-u, v, k);
                    relax(-u, -v, k);
                    relax(v, u, k);
                    relax(v, -u, k);
                    relax(-v, u, k);
                    relax(-v, -u, k);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
