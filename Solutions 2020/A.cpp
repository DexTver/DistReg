#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
//    freopen("input.in", "r", stdin);
//    freopen("output.in", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll a, b, c;
    cin >> a >> b >> c;

    ll s = c * (a / c);
    ll cnt = (b - s) / c;  // количество раз, которое число кратное с встречается на [a, b]

    if (c > b) {
        cout << (b - a + 1) / 2;
        return 0;
    }
    if (c % 2 == 0) {
        if (a % 2 == 1) {
            cout << (b - a + 1) / 2;
        } else {
            if (cnt > 0) {
                cout << (b - a) / 2 + 1;
            } else {
                cout << (b - a + 1) / 2;
            }
        }
        return 0;
    }
    if (s < a) {
        s += c;
    }
    if ((s - a) % 2 == 1) cnt--;
    a += cnt;
    cout << (b - a + 1) / 2 + cnt;
    return 0;
}
