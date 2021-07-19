import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Queries_about_less_or_equal_elements {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
 
    public static void main(String[] args) {
        FastReader in = new FastReader();
        int n1 = in.nextInt();
        int n2 = in.nextInt();
        long arr[] = new long[n1];
        for (int i = 0; i < n1; i++) {
            arr[i] = in.nextLong();
        }
       sort(arr , 0 , arr.length-1);
 
        for (int i = 0; i < n2; i++) {
 
            long tmp = in.nextLong();
            if (arr[0] > tmp) {
                System.out.print(0 + " ");
            } else
                System.out.print(getIndex(tmp, arr, 0, arr.length - 1) + " ");
 
 
        }
        System.out.println();
 
 
    }
     public static int getIndex(long target, long[] arr, int l, int r) {
        if(r<l)
            return 0;
        int index = 0;
        if (arr[r] <= target)
            return r - l + 1;
        if (arr[l] > target)
            return 0;
        else {
            int a = getIndex(target, arr, l, (l + r) / 2);
            int b = getIndex(target, arr, (l + r) / 2 + 1, r);
            return a + b;
 
        }
    }
    static void merge(long arr[], int l, int m, int r)
    {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;
 
        /* Create temp arrays */
        long L[] = new long [n1];
        long R[] = new long [n2];
 
        /*Copy data to temp arrays*/
        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];
 
 
        /* Merge the temp arrays */
 
        // Initial indexes of first and second subarrays
        int i = 0, j = 0;
 
        // Initial index of merged subarry array
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
 
        /* Copy remaining elements of L[] if any */
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
 
        /* Copy remaining elements of R[] if any */
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
 
    // Main function that sorts arr[l..r] using
    // merge()
   static void sort(long arr[], int l, int r)
    {
        if (l < r)
        {
            // Find the middle point
            int m = (l+r)/2;
 
            // Sort first and second halves
            sort(arr, l, m);
            sort(arr , m+1, r);
 
            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }
 
 
}