//package Div2_B;

import java.util.Scanner;

public class Vacations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][]arr = new int[n][2];
        for(int i = 0;i<n;i++)
        {
            int tmp = sc.nextInt();
            if(tmp == 1)
            {
                arr[i][0] = 1;
                arr[i][1] = 0;
            }
            else if(tmp == 2)
            {
                arr[i][0] = 0;
                arr[i][1] = 1;
            }
            else if(tmp == 3)
            {
                arr[i][0] = 1;
                arr[i][1] = 1;
            }
        }

        int res = 0;
        for(int i = 0;i<arr.length-1;i++)
        {
            if(arr[i][0] == 0 && arr[i][1] == 0)
                res++;
            else if(arr[i][0] == 0 && arr[i][1] == 1)
            {
                arr[i+1][1] = 0;
            }else if(arr[i][0] == 1&& arr[i][1] == 0)
                arr[i+1][0] = 0;
        }
        if(arr[n-1][0] + arr[n-1][1] == 0)
            res++;
        System.out.println(res);
    }
}