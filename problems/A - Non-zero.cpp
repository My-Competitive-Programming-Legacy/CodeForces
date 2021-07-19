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
    int q ;
    cin >> q ;
    while(q--) {
        int n ;
        cin >> n ;
        int res  =0 ;
        int sum = 0 ;
        for(int i = 0  ; i< n  ; i++) {
            int t ;
            cin >> t ;
            if(t == 0 ) {
                res ++ ;
                t++ ;
            }
            sum+= t ;
        }
        if(sum == 0) res++ ;
        cout << res << endl  ;

    }
    return 0 ;
    

}