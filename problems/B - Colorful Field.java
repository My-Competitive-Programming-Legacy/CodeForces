
import java.util.Arrays;
import java.util.Scanner;

public class Colorful_Field {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int l = sc.nextInt();
        pair[] arr = new pair[k];
        for(int i = 0 ;i<k;i++)
        {
            arr[i] = new pair(sc.nextInt()-1,sc.nextInt()-1);
        }
        Arrays.sort(arr);
       o: for(int i = 0 ;i<l;i++)
        {
            int x = sc.nextInt()-1;
            int y = sc.nextInt()-1;
            int res  = x*m + y;
            for(int j = 0 ;j<arr.length;j++)
            {
                if(arr[j].x<x ||(arr[j].x==x && arr[j].y<y  ))
                    res--;
                else if(arr[j].x == x && arr[j].y == y)
                {
                    System.out.println("Waste");
                    continue o;
                }else
                    break;
            }
            res%=3;

            System.out.println(res  == 0 ?"Carrots" :res  == 1 ?"Kiwis" :"Grapes");
        }
    }

    static class pair implements Comparable<pair> {
        int x;
        int y;

        pair(int a, int b) {
            x = a;
            y = b;
        }

        public int compareTo(pair o) {
            if (this.x != o.x)
                return this.x - o.x;
            else
                return this.y - o.y;
        }


    }
}