#include <bits/stdc++.h>

#define ll long long int
using namespace std;
const bool MOD_MODE = false;
long long int Mod = 4294967296;

template<class type>
class Matrix {
    int n, m;
public:
    vector<vector<type>> mat;


    Matrix(vector<vector<type>> a) {
        this->mat = a;
        this->n = (int) a.size();
        this->m = (int) a[0].size();
    }


public:
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        mat.resize(n, vector<type>(m));
    }

    Matrix<type> operator*(Matrix o) {
        // n * m // m * l
        vector<vector<type>> a = mat;
        vector<vector<type>> b = o.mat;
        assert(m == (int) b.size());
        vector<vector<type>> ans(n, vector<type>(b[0].size()));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int) b[0].size(); j++) {
                ans[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    if (!MOD_MODE) {
                        ans[i][j] += (a[i][k] * b[k][j]);
                    } else {
                        ans[i][j] += (a[i][k] * 1ULL * b[k][j]) % Mod;
                        ans[i][j] %= Mod;
                    }
                }
            }
        }
        return Matrix<type>(ans);
    }


    Matrix<type> exp(long long int b) {
        Matrix<type> ans(n, m);
        Matrix<type> base(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.mat[i][j] = (i == j);
            }
        }
        while (b > 0) {
            if (b & 1) {
                ans = ans * base;
            }
            base = base * base;
            b >>= 1;
        }

        return ans;
    }
};

vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};

int main() {
    int N = 64;
    int k;
    cin >> k;
    vector<vector<unsigned int >> g(N + 1, vector<unsigned int>(N + 1, 0));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int delta = 0; delta < 8; delta++) {
                int ii = i + dx[delta];
                int jj = j + dy[delta];
                if (ii >= 0 && ii < 8 && jj >= 0 && jj < 8) {
                    int cur_idx = i * 8 + j;
                    int nxt_idx = ii * 8 + jj;
                    g[cur_idx][nxt_idx] = 1;
                    g[nxt_idx][cur_idx] = 1;
                }
            }
        }
    }
    for (int j = 0; j <= N; j++) {
        g[N][j] = 1;
    }
    Matrix<unsigned > base(g);
    base = base.exp(k + 1);
    unsigned ans = base.mat[N][0];

    cout << ans << endl;
}