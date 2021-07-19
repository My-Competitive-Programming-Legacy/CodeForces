import java.util.Scanner;
 
public class Magic_Box {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[]a = new int[7];
        int[]box = new int[4];
        int[]me = new int[4];
        // ignore the zero index
        // take the input
        for(int i = 1;i<4;i++)
        {
            me[i] = sc.nextInt();
        }
        for(int i = 1;i<4;i++)
        {
            box[i] = sc.nextInt();
        }
        for(int i = 1;i<=6;i++)
        {
            a[i] = sc.nextInt();
        }
        long res = 0;
 
 
 
        if(me[1] > box[1])
        {
            res +=a[6];
        }else if (me[1]<0)
        {
            res+=a[5];
        }
 
 
 
        if(me[2] > box[2])
        {
            res +=a[2];
        }else if( me[2]<0)
        {
            res+=a[1];
        }
 
 
 
        if(me[3] > box[3])
        {
            res +=a[4];
        }else if( me[3]<0)
        {
            res+=a[3];
        }
        System.out.println(res);
 
 
 
 
 
    }
}