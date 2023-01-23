#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    ll l, r;

    Node() {
        l = 0;
        r = 0;
    }

    Node(ll _l, ll _r) {
        l = _l;
        r = _r;
    }
};

bool cmp(Node a, Node b) {
    return a.r < b.r;
}

void print(const vector<ll> &a) {
    for (ll tt : a) {
        cout << tt << " ";
    }
    cout << endl;
}

struct SegmentTree {
    ll n;
    vector<ll> a, t;

    SegmentTree(const vector<ll> &data) {
        a = data;
        n = a.size();
        t.resize(4 * a.size());
        build(0, 0, (ll) a.size());
    }

    void build(ll v, ll l, ll r) {
        if (l + 1 == r) {
            t[v] = a[l];
            return;
        }
        ll m = (l + r) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void change(ll v, ll l, ll r, ll pos, ll newVal) {
        if (l + 1 == r) {
            t[v] = newVal;
            a[pos] = newVal;
            return;
        }
        ll m = (l + r) / 2;
        if (pos < m) {
            change(2 * v + 1, l, m, pos, newVal);
        } else {
            change(2 * v + 2, m, r, pos, newVal);
        }
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void change(ll pos, ll newVal) {
        change(0, 0, n, pos, newVal);
    }

    ll get(ll v, ll l, ll r, ll ql, ll qr) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return t[v];
        }
        ll m = (l + r) / 2;
        return get(2 * v + 1, l, m, ql, qr) + get(2 * v + 2, m, r, ql, qr);
    }

    ll get(ll ql, ll qr) {
        return get(0, 0, n, ql, qr);
    }
};

int main() {
//    freopen("input.in", "r", stdin);
//    freopen("output.in", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m, t;
    cin >> n >> m;
    vector<ll> a(m);
    queue<ll> b;
    for (ll i = 0 ; i < m ; ++i) {
        cin >> a[i];
    }
    for (ll i = 0 ; i < n ; ++i) {
        cin >> t;
        b.push(t);
    }

    vector<ll> k;
    vector<bool> used(n, false);
    vector<vector<ll>> indexs(n + 1);
    ll sz = 0;
    for (ll x : a) {
        if (!used[x]) {
            while (true) {
                ll y = b.front();
                bool end = y == x;
                k.push_back(y);
                indexs[y].push_back(sz);
                sz++;
                used[y] = true;
                b.pop();
                if (end) break;
            }
        } else {
            k.push_back(x);
            indexs[x].push_back(sz);
            sz++;
        }
    }
    cout << sz << "\n";
    vector<ll> data(sz, 0);
    SegmentTree tree = SegmentTree(data);
    vector<Node> coms(k.size());
//    for (auto x : indexs) {
//        cout << x.first << "\n";
//        for (auto tt : x.second) {
//            cout << tt << " ";
//        }
//        cout << "\n--------\n";
//    }
    vector<ll> s(n + 1, 0);
    for (ll i = 0 ; i < sz ; ++i) {
        s[k[i]]++;
        if (indexs[k[i]].size() == s[k[i]]) {
            coms[i] = Node(i, sz);
        } else {
            coms[i] = Node(i, indexs[k[i]][s[k[i]]]);
        }
    }
    sort(coms.begin(), coms.end(), cmp);

    map<ll, ll> last;
    ll ind = 0;
    vector<ll> ans(sz, n);
    for (ll i = 0 ; i < sz ; ++i) {
        if (last[k[i]] == 0) {
            last[k[i]] = i + 1;
            tree.change(i, 1);
        } else {
            tree.change(last[k[i]] - 1, 0);
            tree.change(i, 1);
            last[k[i]] = i + 1;
        }

        while (coms[ind].r < i) {
            ind++;
        }
        while (coms[ind].r == i) {
            ans[coms[ind].l] = tree.get(coms[ind].l, coms[ind].r + 1);
            ind++;
        }
    }
    print(ans);
    return 0;
}
