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
#define MOD (int)(1e9) + 7
using namespace std;

/**Global stuff */

/**Global stuff */ ;
int main() {
    int n ;
    cin >> n ;
    vector<int> s(n);
    vector<int> c(n) ;
    int minCost = MAX;
    for(int i = 0 ; i<n ; i++ ) cin >> s[i] ;
    for(int i = 0 ; i<n ; i++ ) cin >> c[i] ;
    for(int i = 0  ; i< n ; i++) {
        int before = MAX ;
        for(int j = 0 ; j < i ; j++ ){
            if(s[j] < s[i] ) before = min(before , c[j]) ;
        }
        int after  = MAX ;
        for(int j = i+1 ; j< n ;j++) {
            if(s[j] > s[i] ) after = min(after , c[j]) ;
        }
        minCost = min(minCost , c[i] + before + after) ;
    }
    if(minCost >= MAX) minCost = -1 ;
    cout << minCost << endl ;
    return 0;
}