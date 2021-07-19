import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class monMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i<n; i++)
        {
            arr[i] = sc.nextInt();
        }
        int Sereja = 0,dema = 0;
        int turn=1;
        int first = 0 ;
        int last = arr.length-1;
        while(last>=first )
        {
            if(turn == 1)
            {
                if(arr[first]> arr[last])
                {
                    Sereja+= arr[first];
                    first++;
                }else
                {
                    Sereja+=arr[last];
                    last--;
                }
                turn = 0;
            }else
            {
                if(arr[first]> arr[last])
                {
                    dema+=arr[first];
                    first++;

                }else
                {
                    dema+= arr[last];
                    last--;
                }
                turn = 1;
            }
        }
        System.out.println(Sereja+" " + dema);

    }
}
