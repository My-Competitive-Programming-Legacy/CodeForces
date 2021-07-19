import java.util.Scanner;
import java.util.TreeSet;

public class Inna_and_New_Matrix_of_Candies {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();
        TreeSet<Integer> arr = new TreeSet<Integer>();
        for (int i = 0; i < n; i++) {
            String s = sc.nextLine();
            int start = -1;
            int end = -1;
            for (int j = 0; j < m; j++) {
             int t = s.charAt(j);
                if(t  == 'G')
                    start = j;
                else if(t =='S')
                    end = j;


            }
            if(start  > end)
            {
                System.out.println(-1);
                return;
            }else
                arr.add(end - start);
        }
        System.out.println(arr.size());



    }
}