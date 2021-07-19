import java.util.Scanner;

public class Dreamoon_and_WiFi {
    static int res = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 =sc.nextLine();
        String s2 =sc.nextLine().replaceAll("\\?","");
        int diff = s1.length()-s2.length() ;
        int res1=0,res2=0;
        for(int i = 0;i<s1.length();i++) res1+= s1.charAt(i) == '+' ? 1 : -1 ;
        for(int i = 0;i<s2.length();i++) res2+= s2.charAt(i) == '+' ? 1 : -1 ;
        getAnswer(diff , res1 , res2);
        System.out.println(res / (double)(1<<diff));




    }
    static void getAnswer(int level,int res1 , int res2)
    {
        if(level == 0)
        {
            if(res1 ==res2)
                res++;
        }
        else
        {
            getAnswer(level-1 , res1 , res2+1);
            getAnswer(level-1 , res1 , res2-1);
        }
    }
}