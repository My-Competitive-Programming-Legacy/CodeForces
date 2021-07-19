import java.util.Scanner;

public class Dubstep {
    public static void main(String[] args) {
        Scanner sc  = new Scanner(System.in);
        String tmp = (sc.nextLine().replaceAll("WUB"," "));
     //   System.out.println(tmp);
        for(int i =0 ;i<tmp.length() ;i++)
        {
            if(tmp.charAt(i) == ' ')
            {
            //    tmp = tmp.substring(0,i) + tmp.substring(tmp.)
            int j;
            for( j = i  ;j<tmp.length()&&tmp.charAt(j) == ' ';j++)
            {

            }
            tmp = tmp.substring(0,i)+" "+ tmp.substring(j);

            }
        }
        System.out.println(tmp);
    }
}