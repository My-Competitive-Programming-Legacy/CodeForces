
import java.util.ArrayList;
import java.util.Scanner;

public class Hamza {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Integer> host = new ArrayList<Integer>();
		ArrayList<Integer> guest = new ArrayList<Integer>();
		int sum=0;
		for(int i = 0 ; i<2*n ; i++)
		{
			if(i%2 == 0 )
			{
				host.add(sc.nextInt());
			}else
			{
				guest.add(sc.nextInt());
			}
		}
		for(int i = 0 ; i<host.size() ; i++)
		{


				for(int j = 0 ;j<guest.size() ;j++)
				{
					if(guest.get(j) == host.get(i))
						sum++;
				}


		}
		System.out.println(sum);
	}





    }