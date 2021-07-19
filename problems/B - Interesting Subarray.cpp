#include <bits/stdc++.h>
using namespace std;
int main() {
int q ;
cin >>q ;
    outer :
while(q--){
	int n ;
	cin >> n ;
	int arr[n+5] ;
	for(int i = 0 ; i< n; i++)
		cin >>  arr[i] ;
	for(int i = 0 ; i< n-1 ; i++){
		if(abs(arr[i] - arr[i+1]) > 1  )
		{
			cout << "yes " << endl;
			cout << i+1 <<" " <<  i+2 << endl  ;
			goto outer ;
		}

	}
	cout << "no"<< endl  ;


}
return 0 ;

}