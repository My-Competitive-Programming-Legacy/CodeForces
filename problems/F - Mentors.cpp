#include <iostream>
#include<bits/stdc++.h>
#define E 10
#define space " "
using namespace std;
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main() {
    IO ;
    int n, k;
    cin >> n >> k;
    int hate[(int) n + E];
    memset(hate , 0 , sizeof hate) ;
    int arr[(int) n + E];
    vector<int> sorted;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        arr[i] = val;
        sorted.push_back(val);
    }
    for (int i = 0; i < k; ++i) {
        int f, s;
        cin >> f >> s;
        if (arr[f] > arr[s]) hate[f]++;
        else if (arr[f] < arr[s]) hate[s]++;
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 1; i <= n; i++) {
        int target = arr[i];
        int idx = lower_bound(sorted.begin() , sorted.end() , arr[i]) - sorted.begin() ;
        cout << max(idx-hate[i] , 0) << space ;
    }
    return 0;
}