

import java.util.Scanner;

public class Hamza {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int r = sc.nextInt();
		int result = 0;

		for(int i = 1 ;i>0 ;i++ )
        {
            if(((k*i)-r)%10 == 0)
            {
                result = i;
                break;
            }else if ((((k*i))%10 == 0))
            {
                result = i;
                break;
            }
        }
		System.out.println(result);

	}





    }