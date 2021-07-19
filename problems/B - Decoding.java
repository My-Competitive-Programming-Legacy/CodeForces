import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class monMain {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nofchars = sc.nextInt();
        String code  =  sc.next();
        System.out.println(extractTheCode("", code));


    }
    public static String insertAtMiddle(String src,char c)
    {
        if(src.length() == 0)
        {
            return src+c;
        }else if (src.length() == 2)
        {
            return src.substring(0,1)+c+src.substring(1);
        }
        int indexOfInsertion = (src.length())/2 ;
        return  src.substring(0,indexOfInsertion) + c + src.substring(indexOfInsertion);
    }
    public static String extractTheCode(String result,String code)
    {
        if(code.length() == 0)
            return result;
        else
        {
            char X = code.charAt(code.length()-1);
            code = code.substring(0,code.length()-1);
           result =  insertAtMiddle(result,X);
        }
        return  extractTheCode(result,code);
    }

}