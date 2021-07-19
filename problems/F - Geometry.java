import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new PrintWriter(System.out));
        int q = Integer.parseInt(sc.readLine());
        while (q-- > 0) {
            String[] s = sc.readLine().split("\\s");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            out.write((a == b ? "Square" : "Rectangle") + "\n");
        }
        out.flush();

    }
}