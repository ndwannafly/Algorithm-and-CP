import java.util.Scanner;

public class Solution {

    private static class Solver{
        public static long solve(long n, long k ){
            long l = (long) Math.sqrt(n);
            if(l*l < n) ++l;
            long r = (long) Math.sqrt(k);
            if(r*r > k) --r;
            return r-l+1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();
        Solver solver = new Solver();
        while(test-->0){
            long n = sc.nextLong();
            long k = sc.nextLong();
            System.out.println(solver.solve(n,k));
        }


        //System.out.println(solver.solve(s,t,n));
    }
}
