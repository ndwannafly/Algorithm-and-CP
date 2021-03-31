import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    static class Solver{
        public BigInteger solve(int n){
            BigInteger res = new BigInteger("1");
            for(int i = 1; i <= n; i++){
                res = res.multiply(BigInteger.valueOf(i));
            }
            return res;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Solver solver = new Solver();
        System.out.println(solver.solve(n));
    }
}
