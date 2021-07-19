import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        while (q-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr);
            Set<Integer> set = new HashSet<>();
             int res = 0 ;
            for (int i = 0; i < n; i++) {
                if (set.add(arr[i])) {
                    if (arr[i]%2 == 0){
                        arr[i]/=2;
                        res ++ ;
                    }
                    while (arr[i] % 2 == 0 && !set.contains(arr[i])) {
                        arr[i] /= 2;
                        res++;
                    }
                }
            }
        System.out.println(res);

    }
}

}