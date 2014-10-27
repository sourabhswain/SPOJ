import java.io.*;
/**
 * Classic Coupon Collector's Problem..
 * @author Sunny
 *
 */
public class FAVDIC {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    public static void main(String[] args) throws IOException {
        new FAVDIC().run();
    }

    void run() throws IOException {
        int testcases = Integer.parseInt(in.readLine());
        while (testcases-- > 0)
            solve(Integer.parseInt(in.readLine()));
        out.flush();
    }

    void solve(int n) {
        double result = 0.0;
        for (int i = 1; i <= n; i++)   
            result += n / (double)i;
        out.printf("%.2f\n", result);
    }
}
