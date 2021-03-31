import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {

    private static long n,k,x,y;
    private static class Solver{
        private Map<Long, Boolean> mark = new HashMap<Long, Boolean>();

        private long getXY(long x,long y){
            return (x-1) * n + y;
        }

        public long solve(long n, long k, long x, long y) {
            while (k-- > 0) {
                long u = sc.nextLong();
                long v = sc.nextLong();
                mark.put(getXY(u, v), true);
            }

            long res = 0;
            long left = y, right = y;
            for (long i = y - 1; i >= 1; i--) {
                if (mark.get(getXY(x, i))!= null) break;
                left = i;
            }

            for (long i = y + 1; i <= n; i++) {
                if (mark.get(getXY(x, i))!=null) break;
                right = i;
            }
            res += right - y;
            res += y - left;
            left = x;
            right = x;
            for (long i = x - 1; i >= 1; i--) {
                if (mark.get(getXY(i, y))!=null) break;
                left = i;
            }

            for (long i = x + 1; i <= n; i++) {
                if (mark.get(getXY(i, y))!=null) break;
                right = i;
            }

            res += right - left;
            left = 0;
            right = 0;
            for (long i = 1; i <= n; i++) {
                long ii = x + i;
                long jj = y + i;
                if (ii > n || jj > n) break;
                if (mark.get(getXY(ii, jj))!=null) break;
                right = i;
            }

            for (long i = 1; i <= n; i++) {
                long ii = x - i;
                long jj = y - i;
                if (ii < 1 || jj < 1) break;
                if (mark.get(getXY(ii, jj))!=null) break;
                left = i;
            }

            res += right + left;

            left = 0;
            right = 0;

            for (long i = 1; i <= n; i++) {
                long ii = x - i;
                long jj = y + i;
                if (ii < 1 || jj > n) break;
                if (mark.get(getXY(ii, jj))!=null) break;
                left = i;
            }
            for (long i = 1; i <= n; i++) {
                long ii = x + i;
                long jj = y - i;
                if (ii > n || jj < 1) break;
                if (mark.get(getXY(ii, jj))!=null) break;
                right = i;
            }

            res += right + left;
            return res;
        }
    }

    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        n = sc.nextLong();
        k = sc.nextLong();
        x = sc.nextLong();
        y = sc.nextLong();
        Solver solver = new Solver();
        System.out.println(solver.solve(n,k,x,y));
    }
}
