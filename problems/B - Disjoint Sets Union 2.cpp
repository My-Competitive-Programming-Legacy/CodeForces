#include <bits/stdc++.h>

using namespace std;

struct Dsu {
    vector<int> dsu;
    vector<int> size;
    vector<int> mn, mx;
    int n;

    Dsu(int n) {
        this->n = n;
        dsu.resize(n);
        size.resize(n);
        mn.resize(n);
        mx.resize(n);
    }

    void init() {
        for (int i = 0; i < n; i++) {
            dsu[i] = i;
            size[i] = 1;
            mn[i] = i;
            mx[i] = i;
        }
    }

    int get_parent(int u) {
        if (dsu[u] == u) return u;
            // path compression
        else
            return dsu[u] = get_parent(dsu[u]);
    }

    bool merge(int u, int v) {
        int pu = get_parent(u);
        int pv = get_parent(v);

        if (pu == pv)
            return false;

        if (size[pu] > size[pv]) {
            swap(pu, pv);
        }
        // the one with larger size is the parent
        // pu -> the smaller size
        dsu[pu] = pv;
        size[pv] += size[pu];
        mn[pv] = min(mn[pu], mn[pv]);
        mx[pv] = max(mx[pu], mx[pv]);
        return true;
    }

    vector<int> get(int u) {
        int pu = get_parent(u);
        return {mn[pu]+ 1 , mx[pu] + 1 , size[pu]};
    }

    int count_components() {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dsu[i] == i) {
                ans += 1;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    Dsu dsu(n);
    dsu.init();
    while (q--) {
        string s;
        int u, v;
        cin >> s >> u;
        u -= 1;
        if (s[0] == 'g') {
            for (auto val : dsu.get(u)) {
                cout << val  << ' ';
            }
            cout << '\n';
        } else {
            cin >> v ;
            v-=1 ;
            dsu.merge(u, v);
        }
    }
    return 0;
}