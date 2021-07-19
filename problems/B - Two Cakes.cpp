    #include <iostream>

    using namespace std;
    int arr1[100005];
    int arr2[100005];
    int main() {
       int n ;
       cin>>n;
        arr1[0]=1;
        arr2[0]=1;
        int g;
        for (int i = 1; i <=2* n; ++i) {
            cin>>g;
            if(arr1[g]==0)arr1[g]=i;
            else arr2[g]=i;
        }
        long long  ans =0;
        for (int j = 1; j <=n ; ++j) {
            ans+=abs(arr1[j]-arr1[j-1]);
            ans+=abs(arr2[j]-arr2[j-1]);
        }
        cout<<ans;
        return 0;
    }