#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vi res;
        for (int i = 0; i < ((n + 1) /2); i++) {
                res.push_back(a[i]) ;
                if(n - 1 != 2 *i )  res.push_back(a[n - i -  1 ]);

        }
       reverse(res.begin(), res.end());
        for (int i = 0; i < n; i++) cout << res[i] << space;
        cout << endl;
    }
    return 0;

}