#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
//    freopen("input.in", "r", stdin);
//    freopen("output.in", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    int r = rnd() % 1000;
    cout << rnd() % r << " " << r << " " << 2 * rnd() % 1000 + 1;
    return 0;
}
