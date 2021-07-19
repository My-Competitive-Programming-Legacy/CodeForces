    import java.util.ArrayList;
    import java.util.Arrays;
    import java.util.Scanner;

    public class Main {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[]arr = new int[105];
            for (int i = 0;i<m;i++)
            {
                int f = sc.nextInt();
                int t = sc.nextInt();
                int p = sc.nextInt();
                arr[f] -=p;
                arr[t]+=p;
            }
            int res=0;
            for (int i = 0; i <105 ; i++) {
                res+= Math.max(0, arr[i]);
            }
            System.out.println(res);



        }


    }