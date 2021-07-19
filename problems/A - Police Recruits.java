import org.w3c.dom.Node;

import java.util.*;

public class monMain {
    public static void main(String[] args) {
        int officer = 0;
        // int crimes = 0;
        int untreated = 0;
        int input = 0;
        int events;
        Scanner sc = new Scanner(System.in);
        events = sc.nextInt();
        for (int i = 0; i < events; i++) {
            input = sc.nextInt();
            if (input > 0)
                officer += input;
            else if (input < 0) {
                //crimes ++;
                if (officer > 0)
                    officer--;
                else
                    untreated++;
            }

        }
        System.out.println(untreated);

    }
}






