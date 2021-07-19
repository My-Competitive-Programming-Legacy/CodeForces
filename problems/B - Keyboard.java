import java.awt.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class Keyboard {
    static double E = 0.0000000001;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        sc.nextLine();
        char[][] arr = new char[n][m];
        List<Integer> Xshift = new ArrayList<Integer>();
        List<Integer> Yshift = new ArrayList<Integer>();
        HashMap<Character ,Integer> hm = new  HashMap<Character , Integer>();
        for(int i = 0 ;i<n;i++)
        {
            String s = sc.nextLine();
            for(int j = 0 ;j<m;j++)
            {
                arr[i][j] = s.charAt(j);

                if(arr[i][j] == 'S')
                {
                    Xshift.add(i);
                    Yshift.add(j);
                }else
                    hm.putIfAbsent(arr[i][j], 1);

            }
        }

        //for(int i = 0 ;i<n;)
        for(int k = 0;k<Xshift.size();k++)
        {
            int r = Xshift.get(k);
            int c = Yshift.get(k);
            for(int i = 0 ;i<n;i++)
            {
                for(int j = 0 ;j<m;j++)
                {
                    double l = Math.sqrt((r-i)*(r-i)+(c-j)*(c-j));
                    if(Math.abs( l - (double)x)  < E || l <= x )
                    {
                        hm.replace(arr[i][j] , 0);
                    }
                }
            }
        }
        sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        int res= 0;
        for(int i = 0;i<s.length();i++)
        {
            if(hm.get(s.charAt(i)) == null)
            {
                if(Xshift.isEmpty() ||  hm.get(Character.toLowerCase(s.charAt(i))) == null)
                {
                    System.out.println(-1);
                    return;
                }
               res+= hm.get(Character.toLowerCase(s.charAt(i)));
            }
        }
        System.out.println(res);


    }
}