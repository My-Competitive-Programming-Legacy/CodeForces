

import java.util.ArrayList;
import java.util.Scanner;

public class TaskB {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n];
        int[] parents = new int[n];
        int[] dsu = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            dsu[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            makeUnion(a,b,dsu);
        }

        for(int i = 0 ;i<dsu.length;i++)
        {
            parents[getParent(dsu[i],dsu)]+=arr[i];
        }
        for(int i : parents)
        {
            if(i!=0)
            {
                System.out.println("IMPOSSIBLE");
                return;
            }
        }
        System.out.println("POSSIBLE");


    }

    static int getParent(int a, int[] dsu) {
        if (dsu[a] == a)
            return a;
        else
            return dsu[a] = getParent(dsu[a], dsu);
    }
    static void makeUnion(int a, int b , int[]arr)
    {
        int x = getParent(a,arr);
        int y = getParent(b,arr);

        arr[x] = arr[y];
    }


}