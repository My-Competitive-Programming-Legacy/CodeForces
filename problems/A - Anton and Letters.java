import java.util.HashSet;
import java.util.Scanner;

public class AntonAndLetters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashSet<Integer> arr = new HashSet<Integer>();
        String Line = sc.nextLine();
        for(int i = 1 ;i<Line.length() &&Line.length()!=2 ;i+=3)
        {

               arr.add(Character.getNumericValue(Line.charAt(i)));
        }
        System.out.println(arr.size());

    }
}