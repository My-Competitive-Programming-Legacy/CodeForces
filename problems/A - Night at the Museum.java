import java.util.Scanner;

public class Hamza {
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	String input = sc.nextLine();
    	int sum = 0;char position = 'a';
    	for(int i = 0 ; i<input.length() ; i++)
		{
			sum += min(position,input.charAt(i));
			position = input.charAt(i);
		}
    	System.out.println(sum);
		





    	}
    	public  static int min(char start , char end) {
    		int x = Math.abs(start -end);
    		int y = Math.abs(26-Math.abs(end -start));
    		return x<y ?  x : y;

		}





    }