#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back

#define MOD (int)(1e9  + 7)

int main() {
    int q;
    cin >> q;
    while (q--) {
        int x, n, m;
        cin >> x >> n >> m;
        bool ok = false;
        while (n > 0 && m > 0) {
            if (x / 2 + 10 < x) {
                x /= 2;
                x += 10;
                n--;
            } else {
                m--;
                x -= 10;
            }
        }
        if (x < 1) ok = true;
        while (n > 0) {
            x /= 2;
            x += 10;
            n--;
            if (x < 1) ok = true;
        }
        x -= 10 * m;
        if (x <= 0 || ok) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;

}