import java.util.ArrayList;
import java.util.Scanner;
public class CarrotCakes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a=0,b=0,c=0;
       // int[] arr = new int[n];
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i = 0 ;i<n ;i++)
        {
            arr.add(i,sc.nextInt());
            if(arr.get(i) == 1 )
                a++;
            else if (arr.get(i) == 2)
                 b+=1 ;
            else
                c++ ;
        }
        int numberOfTeams = (a<b ? a : b) < c ? (a<b ? a : b) : c;
        System.out.println(numberOfTeams);
        for(int i = 0 ;i< numberOfTeams;i++ )
        {
            System.out.print(arr.indexOf(1)+1 + " ");
            arr.set(arr.indexOf(1) , 0);
            System.out.print(arr.indexOf(2)+1 + " ");
            arr.set(arr.indexOf(2) , 0);
            System.out.println(arr.indexOf(3)+1);
            arr.set(arr.indexOf(3) , 0);
        }
    }

}