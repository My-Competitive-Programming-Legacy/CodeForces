import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Filya_and_Homework {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Set<Integer> arr = new HashSet<Integer>();
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }
        if (arr.size() < 3)
            System.out.println("YES");
        else if (arr.size() > 3) {
            System.out.println("NO");
        } else {
            Integer[] arr2 = arr.toArray(new Integer[3]);
            Arrays.sort(arr2);
            int x = (arr2[2] - arr2[0] )/ 2;

            if (arr2[0]+ x ==arr2[1]  && arr2[1]+x ==arr2[2] )
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
