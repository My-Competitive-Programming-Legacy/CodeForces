#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endll "\n"
#define ar array
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 301;
const int N = 2005;
const int MOD = 1e9 + 7;
const int maxN = 4e5 + 3;


struct sparse_min {
    vector<int> vec;
    vector<vector<int>> vec_sp;
    int n;

    sparse_min(vector<int> te) {
        vec = te;
        n = te.size();
        vec_sp.resize(n + 1, vector<int>(20));
        for (int i = 0; i < n; i++) {
            vec_sp[i][0] = vec[i];
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                vec_sp[j][i] = min(vec_sp[j][i - 1], vec_sp[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int query(int l, int r) {
        assert(r >= l);
        int ss = log2(r - l + 1);
        return min(vec_sp[l][ss], vec_sp[r - (1 << ss) + 1][ss]);
    }
};

struct sparse_max {
    vector<int> vec;
    vector<vector<int>> vec_sp;
    int n;

    sparse_max(vector<int> te) {
        vec = te;
        n = te.size();
        vec_sp.resize(n + 1, vector<int>(20));
        for (int i = 0; i < n; i++) {
            vec_sp[i][0] = vec[i];
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                vec_sp[j][i] = max(vec_sp[j][i - 1], vec_sp[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int query(int l, int r) {
        assert(r >= l);
        int ss = log2(r - l + 1);
        return max(vec_sp[l][ss], vec_sp[r - (1 << ss) + 1][ss]);
    }
};

int main() {
    //      cout << fixed << setprecision(2);
    IO;
    int n;
    cin >> n;
    vector<int> x1(n);
    vector<int> x2(n);
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];

    }
    sparse_max seg_x1(x1);
    sparse_min seg_x2(x2);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int lb = 1, rb = min(n - i, x2[i] - x1[i] + 1);
        while (lb <= rb) {
            int mb = (lb + rb) / 2;
            int max_x1 = seg_x1.query(i, i + mb - 1);
            int min_x2 = seg_x2.query(i, i + mb - 1);

            if (min_x2 - max_x1 + 1 >= mb) {
                ans = max(ans, mb);
                lb = mb + 1;
            } else {
                rb = mb - 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}