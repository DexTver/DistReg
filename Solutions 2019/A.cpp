#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
//    freopen("input.in", "r", stdin);
//    freopen("output.in", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll l, r, a, x, d;
    cin >> l >> r >> a;
    d = r - l;
    x = d / a;
    ll ans = ((x * (x + 1)) / 2) * (d % a + 1) + (((x - 1) * x) / 2) * (a - d % a - 1);
    cout << ans;
    return 0;
}
