import java.io.*;
import java.util.ArrayList;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
         int q = Integer.parseInt(sc.readLine());
        while (q-- > 0) {
            char[] arr = sc.readLine().trim().toCharArray();
            ArrayList<Integer> idx = new ArrayList<>();
            int res = 0 ;
            for(int i = 0 ; i < arr.length ;)
            {
                int step = 1 ;
                //int j = i;
                if(i+4 <arr.length &&arr[i] == 't'&&arr[i+1] == 'w'&&arr[i+2] == 'o'&&arr[i+3] == 'n'&&arr[i+4] == 'e') {
                    step = 5 ;
                  //  System.out.println("want to index number "+ (i+step) );
                  //  out.print((i + 3) + " ");
                    idx.add(i+3);
                    res ++;
                }else if(i+2< arr.length  &&  arr[i] == 't'&&arr[i+1] == 'w'&&arr[i+2] == 'o'){
                    step = 3 ;
                  //  System.out.println("want to index number "+ (i+step) );
                  //  out.print((i+2)+ " ");
                    idx.add(i+2);
                    res ++ ;
                }else if(i+2<arr.length  &&  arr[i] == 'o'&&arr[i+1] == 'n'&&arr[i+2] == 'e'){
                    step = 3 ;
                 //   System.out.println("want to index number "+ (i+step) );
                    res ++ ;
                    idx.add(i+2);
                  //  out.print((i+2)+ " ");
                }
                i+=step ;
            }
            out.println(res);
            for(int i : idx ){
                out.print(i+ " ");
            }
            out.print("\n");
            out.flush();

        }
        out.close();

    }
}