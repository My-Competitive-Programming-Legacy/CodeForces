#include <iostream>
using namespace std ;
#define E 10
int a[1000+ E ] ;
int main() {
    int n ;
    cin >> n ;
    for(int i = 1 ; i <=n ; ++i) cin >> a[i] ;
    int visited[n+E ] ;
    for(int i = 1 ;i <=n ; ++i) {
        for(int j =  1 ; j <= n ; j++) visited[j] = 0 ;
        int cur = i  ;
        while(!visited[cur]) {
            visited[cur] = 1 ;
            cur = a[cur] ;
        }
        cout << cur  << " ";
    }

    return 0;
}