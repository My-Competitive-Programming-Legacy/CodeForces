import java.util.Arrays;
import java.util.Scanner;

public class Number_Circle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();


        long[] arr = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextLong();


        long[] res = new long[n];
        Arrays.sort(arr);
        reverse(arr);

        int k = 0;
        res[n / 2] = arr[k++];
        //res[n/2+1] = arr[k++];
        //res[n/2-1] = arr[k++];
        for (int i = n / 2, j = n / 2; i > 0 || j < n; i--, j++) {
            if (valid(i, arr))
                k = addNeighbours(arr, (i), k, res);
            if ((valid(j, arr)))
                k = addNeighbours(arr, (j), k, res);
        }
        if(test(res) )
        {
            System.out.println("YES");
            for (int i = 0; i < res.length; i++) {
                System.out.print(res[i] + " ");
            }
        }else
        {
            System.out.println("NO");
        }



    }

    public static int addNeighbours(long[] arr, int i, int k, long[] res) {
        if (valid(i + 1, arr) && res[i + 1] == 0) {
            res[i + 1] = arr[k++];
        } else if (valid(i - 1, arr) && res[i - 1] == 0) {
            res[i - 1] = arr[k++];
        }
        return k;
    }

    public static boolean valid(int i, long arr[]) {
        return i < arr.length && i >= 0;
    }

    public static void reverse(long[] arr) {
        for (int i = 0, j = (arr.length - 1); i < j; i++, j--) {
            long tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    public static boolean test(long arr[])
    {
        for(int i = 1 ; i<arr.length-1 ;i++ )
        {
            if(arr[i+1]+arr[i-1] <= arr[i])
                return false;

        }
        if(arr[0]+arr[arr.length-2] <=  arr[arr.length-1]  )
            return  false;
        if(arr[1] + arr[arr.length-1] <= arr[0])
            return false;

        return true;
    }
}
