import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class monMain {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[][] arr = new char[n][n];
        int[][] visited = new int[n][n];
        for (int i = 0; i < n; i++) {

            String tmp = sc.next();
            for (int j = 0; j <n; j++) {
                arr[i][j] = tmp.charAt(j);
                visited[i][j] = 0;
                if (arr[i][j] == '#')
                    visited[i][j] = -1;
            }
        }
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (arr[i][j] == '.') {
                    if (visited[i][j] == 0 && visited[i - 1][j] == 0 && visited[i][j - 1] == 0 && visited[i + 1][j] == 0 && visited[i][j + 1] == 0) {
                        if (arr[i][j] == '.' && arr[i][j - 1] == '.' && arr[i - 1][j] == '.' && arr[i + 1][j] == '.' && arr[i][j + 1] == '.') {
                            visited[i][j] = 1;
                            visited[i][j - 1] = 1;
                            visited[i - 1][j] = 1;
                            visited[i + 1][j] = 1;
                            visited[i][j + 1] = 1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println("YES");


    }

    public static boolean validBorders(int i, int j, int max) {
        return i != 0 && j != 0 && i != (max - 1) && j != (max - 1);
    }

}