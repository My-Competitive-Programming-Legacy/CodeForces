
import java.util.Arrays;
import java.util.Scanner;
 
public class SortTheArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] arr2 = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            arr2[i] = arr[i];
        }
        Arrays.sort(arr2);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != arr2[i]) {
                l = i;
                break;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (arr[j] != arr2[j]) {
                r = j;
                break;
            }
        }
        boolean flag = true;
        for (int i = l, k = 0;i<r;i++,k++) {
            if (arr[i] != arr2[r-k]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            System.out.println("yes");
            System.out.println((l + 1) + " " + (r + 1));
        } else
            System.out.println("no");
 
 
    }
}