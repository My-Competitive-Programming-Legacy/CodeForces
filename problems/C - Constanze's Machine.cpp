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
#define MAX 2e6
#define MOD (int)(1e9) + 7
using namespace std;
using namespace std;

/**Global stuff */

/**Global stuff */
int dp[100009] ;
int main() {
    string s ;
    cin >>s ;
    if(s.find_first_of('m') != string::npos || s.find_first_of('w') != string::npos) return cout << 0 , 0 ;
    for(int i =0  ; i <=(int)s.size() ; i++) {
        if(i <= 1 ) dp[i] = 1;
        else if (i == 2 ) dp[i] = 2 ;
        else dp[i] = (dp[i-1] + dp[i-2]) %(MOD);
    }
    ll res = 1 ;
    for(int i = 0 ; i< (int)s.size() ;) {
        if(s[i] == 'u' || s[i] == 'n'){
            char cur = s[i] ;
            int len = 1;
            for(int j = i+1 ; j <(int)s.size() && s[j] == cur ; j++) len ++ ;
            res*= dp[len] ;
            res%=MOD ;
            i+=len ;
            i-=1 ; // as we will go up out of the if
        }
        i++ ;
    }
    cout << res << endl ;



    return 0;
}