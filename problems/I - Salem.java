import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new PrintWriter(System.out));
        int q = Integer.parseInt(sc.readLine());
        while (q-- > 0) {
            int n  = Integer.parseInt(sc.readLine());
            int[]arr=  new int[n];
            for (int i = 0; i <n ; i++) {
                arr[i] = Integer.parseInt(sc.readLine());
            }
            int max = 0;
            for (int i = 0; i <n ; i++) {
                for (int j = i+1; j <n ; j++) {
                    int res = arr[i] ^arr[j] ;
                    int tmp = 0;
                    while(res !=0)
                    {
                        tmp+= res%2;
                        res/=2;
                    }
                    max = Math.max(tmp , max);
                }
            }
            out.write(max+"\n");
            out.flush();

        }

    }
}