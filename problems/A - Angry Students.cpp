#include <iostream>
#include <vector>
#include <regex>

using namespace std;
int main() {
    int q , n ;
    cin >> q ;
    while(q-- ) {
        cin >> n ;
        char a[n+5] ;
        for(int i = 0 ; i<n ; i++ ) cin >> a[i] ;

        bool flag = true ;
        int res =0 ;
        while(flag ) {
            bool change = false ;
            for(int i = n-1 ; i >0 ; --i) {
                if(a[i] == 'P' && a[i-1] == 'A')
                {
                    a[i] = 'A' ;
                    change = true ;
                }

            }
            if(!change) flag = false ;else res++ ;

        }
        cout << res << endl ;

    }


}