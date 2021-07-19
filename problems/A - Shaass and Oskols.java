import java.util.Scanner;

public class ShaassandOskols {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0 ;i<n ;i++)
        {
            arr[i] = sc.nextInt();
        }
        int k = sc.nextInt();  //number of shots
        for(int i = 0;i<k ;i++)
        {
            int x = sc.nextInt();
            int y = sc.nextInt();
            shot(arr,x,y);
        }
        for(int i =0 ;i<n ;i++)
        {
            System.out.println(arr[i]);
        }

    }
    public static void shot (int[] arr,int x,int y)
    {
        //System.out.println("HH");
        int n = arr.length;
        if(x < n )
            arr[(x+1)-1] += arr[(x)-1]  - y;    //left
        if( x >1 )
            arr[(x-1)-1] +=  y  - 1;    //right
        arr[x-1] =  0;
    }
}