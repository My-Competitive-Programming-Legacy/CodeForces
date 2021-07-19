import java.util.Scanner;
import java.util.Stack;

public class Regular_Bracket_Sequence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[]arr = sc.nextLine().toCharArray();
        Stack<Character> st = new Stack<>();
        int reomve = 0;
        for(int i = 0;i<arr.length;i++)
        {
            if(arr[i] == '(')
                st.push('(');
            else if(arr[i] == ')' && !st.isEmpty())
                st.pop();
            else
                reomve++;
        }
        System.out.println((arr.length - reomve - st.size()));

    }
}