#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back

int main() {
    int n , m ;
    cin >> n >> m ;
    vector<ll> l(m) ;
    vector<ll> ans(m) ;
    vector<ll> suff(m) ;
    for(int i =0  ; i < m ; i++ ){
        cin >> l[i]  ;
    }
    for(int i = m-1 ; i>=0  ;i--) {
        if(i == m - 1 ) suff[i] = l[i] ;
        else suff[i] = suff[i+1] + l[i] ;
    }
    if(suff[0] < n || m > n ) {
        cout << -1 << endl ;
        return 0 ;
    }
    ans[0] = 1 ;
    int lc = l[0] ;
    for(int i =1; i < m ; i++) {
        bool ok = false ;


         // Here we want to get 1- ans[i]     2- lc

         int lo = ans[i-1] + 1 , up = lc + 1 ;
         while(lo <= up) {
             int mid = lo + (up - lo ) / 2 ;
             if(suff[i] + mid - 1 >= n ) {
                 ok = true ;
                 ans[i] = mid ;
                 up = mid - 1 ;
             }else
                 lo = mid + 1 ;
         }
         if(ok ) {
             lc = ans[i] + l[i] ;
         }


//        for(int j = ans[i-1] + 1  ; j <= lc + 1 ; j++){ // brute force for fucking checking the idea :)
//            if(suff[i] + j - 1 >= n  ) {
//                ok = true ;
//                ans[i] = j ;
//                lc = j + l[i] ;
//                break ;
//            }
//        }



        if(!ok || ans[i] + l[i] - 1 > n) {
            cout << -1 << endl;
            return 0 ;
        }
    }
    for(auto i : ans) {
        cout << i << space ;
    }



    return 0;

}