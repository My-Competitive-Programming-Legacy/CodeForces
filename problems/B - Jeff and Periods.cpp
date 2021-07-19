#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#define MAX  100005
using namespace std;

int main() {

      int n;
      int res = 0;
      cin >> n;
        int last[MAX];
        int ok [MAX];
        int diff [MAX];
        for (int i = 0; i < MAX; i++) {
            last[i] = -1;
            ok[i] = 0;
            diff[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int x ;
            cin >> x;
            if (last[x] == -1) {
                ok[x] = 1;
                res++;
                last[x] = i;
            } else {

                if (diff[x] == 0) {
                    diff[x] = i - last[x];
                    last[x] = i;
                } else if (ok[x] == 1) {
                    if (i - last[x] != diff[x]) {
                        ok[x] = 0;
                        res--;
                    }
                    last[x] = i;
                }
            }
        }


        printf("%d\n",res);
        for (int i = 0; i < MAX; i++) {
            if (ok[i] == 1)
               {
                   printf("%d %d\n",i,diff[i]);
        }
        }
    }



