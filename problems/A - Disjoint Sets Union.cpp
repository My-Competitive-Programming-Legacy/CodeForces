#include <bits/stdc++.h>

using namespace std;

struct Dsu {
    int *dsu;
    int *size;
    int n ;
    Dsu(int n) {
        this->n  = n ;
        dsu = (int *) malloc(n * sizeof(dsu)) ;
        size = (int *) malloc(n * sizeof(dsu)) ;
    }

    void init() {
        for (int i = 0; i < n; i++) {
            dsu[i] = i;
            size[i] = 1;
        }
    }

    int get_parent(int u) {
        if (dsu[u] == u) return u;
        else return dsu[u] = get_parent(dsu[u]);
    }

    bool merge(int u, int v) {
        int pu = get_parent(u);
        int pv = get_parent(v);
        if (pu == pv) return false;

        if (size[pu] > size[pv]) {
            swap(pu, pv);
        }
        // the one with larger size is the parent
        // pu -> the smaller size
        size[pv] += size[pu];
        dsu[pu] = pv;
        return true;
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
        cin >> s >> u >> v;
        u -= 1;
        v -= 1;
        if (s[0] == 'g') {
            if (dsu.get_parent(u) == dsu.get_parent(v)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            dsu.merge(u, v);
        }
    }
    return 0;
}