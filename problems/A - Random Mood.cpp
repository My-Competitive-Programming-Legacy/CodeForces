
#include <bits/stdc++.h>

using namespace std;

template<class type>
class Matrix {

    int n, m;
public:
    vector<vector<type>> mat;

private:
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

    Matrix operator*(Matrix const &o) {
        // n * m // m * l
        vector<vector<type>> a = mat;
        vector<vector<type>> b = o.mat;
        assert(m == (int) b.size());
        vector<vector<type>> ans(n, vector<type>(b[0].size()));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int) b[0].size(); j++) {
                ans[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    ans[i][j] += (a[i][k] * b[k][j]);
                }
            }
        }
        return Matrix(ans);
    }


    Matrix exp(int b) {
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


int main() {
    cout << fixed << setprecision(20) ;
    int n;
    double p;
    cin >> n >> p;
    Matrix<double> base(2, 2);
    base.mat = {{1 - 2 * p, 1},
                {0,1}};

    base = base.exp(n);
    vector<vector<double>> ans = base.mat;

    cout << ans[0][0] + p * ans[0][1] << endl;
}