#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
using namespace std;


/**Global stuff */

/**Global stuff */
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> ar;
        for (int i = 0; i < 2 * n; i++) {
            int t;
            cin >> t;
            ar.push_back(t);
        }
        sort(ar.begin(), ar.end());
        int res = (int) 1e9;
        for (int i = 1; i < 2 * n - 1; i++) {
            if (i >= 2 * n / 2)
                res = min(res, abs(ar[2 * n / 2 - 1] - ar[i]));
            else
                res = min(res, abs(ar[2 * n / 2] - ar[i]));
        }
        cout << (n ==1 ?  ar[1] -ar[0] : res) << endl ;
    }
    return 0;


}