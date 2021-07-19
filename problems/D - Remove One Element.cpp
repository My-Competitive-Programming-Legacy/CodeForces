#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>

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
    int n;
    cin >> n;
    vector<int> a;
    vector<int> pre(n+5);
    vector<int> post(n+5);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    bool sorted = true ;
    for(int i = 1 ; i<n ; i++ ) if(a[i] <= a[i-1]) sorted = false ;
    if (sorted)
        return cout << n, 0;
    int maxi = 1 ;
    int temp = 1;
    for(int i = 1  ; i< n ; i++) {
        if(a[i] > a[i-1]) temp++ ;
        else temp = 1 ;
        maxi = max(temp , maxi) ;
    }
    pre[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) pre[i] = 1 + pre[i - 1];
        else pre[i] = 1;
    }
    post[n - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < a[i + 1]) post[i] = 1 + post[i + 1];
        else post[i] = 1;
    }
    for (int i = 1; i < n - 1; i++) {
        //cout << i-1 << " and " << i+1 << endl ;
        if (a[i - 1] < a[i + 1])
            maxi = max(maxi, pre[i - 1] + post[i + 1]);
    }
    cout << maxi << endl;

    return 0;


}