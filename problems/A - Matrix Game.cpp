#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define ACCURATE cout << fixed << setprecision(20)
#define debug(val) "[ " << #val " : " << (val) << " ]\n"
#define space " "
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define ff first
#define ss second
#define PI atan(1)*4


void solve() {
	int n , m ; 
	cin >> n >> m ; 
	int a[52][52] ; 
	for(int i=0;i<n;i++ ){
		for(int j =0;j<m;j++ ){
			cin >> a[i][j] ; 
		}
	}
	set<int > rs, cs ; 
	for(int i=0;i<n;i++ ){
		for(int j=0;j<m ;j++ ){
			if(a[i][j] == 1 ){
				rs.insert(i) ; 
				cs.insert(j) ; 
			}
		}
	}
	int r = n -(int)rs.size() ; 
	int c = m-(int)cs.size() ; 
	int ans = min(r , c ) ; 
	cerr << debug(r) << debug(c) ; 
	if(ans %2 == 0 ) 
		cout << "Vivek" << endl; 
	else 
		cout << "Ashish" << endl; 
				
	
}
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}