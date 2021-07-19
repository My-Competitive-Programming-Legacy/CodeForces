#include <iostream>
using namespace std;
int main() {
    int n ;
    cin>>n ;
    string t;
    cin>>t;
    int x=0;
    for(int i=0;i<n;i++){
        if(t[i]=='8')x++;
    }
    cout<<min(x,n/11);
    return 0;
}