import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class monMain {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();
        int n = sc.nextInt();
        int max = 1;
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }
        for (int i = 0; i < arr.size(); i++) {

            int j = i, right = 0, left = 0;
            while (j < arr.size() - 1) {
                if (arr.get(j) >= arr.get(j + 1)) {
                    right++;
                    j++;
                } else
                    break;
            }
            j = i;
            while (j > 0) {
                if (arr.get(j - 1) <= arr.get(j)) {
                    left++;
                    j--;
                } else
                    break;
            }
            max = (left + right +1) > max ? (left + right +1) : max;
        }
        System.out.println(max);


    }

}