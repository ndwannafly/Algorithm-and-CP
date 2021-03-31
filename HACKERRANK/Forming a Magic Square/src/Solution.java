import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static class Solver{
        private int res = Integer.MAX_VALUE;
        private int[] x = new int[10];
        private boolean[] mark = new boolean[10];

        private boolean check(int[] a){
            int[] sum = new int[10];
            int cnt = 0;
            for(int i=0; i<3; i++){
                ++cnt;
                for(int j=0; j<3; j++){
                    sum[cnt] += a[getXY(i,j)];
                }
            }
            for(int i=0; i<3; i++){
                ++cnt;
                for(int j=0; j<3; j++){
                    sum[cnt] += a[getXY(j,i)];
                }
            }
            sum[++cnt] = a[getXY(0,0)] + a[getXY(1,1)] + a[getXY(2,2)];
            sum[++cnt] = a[getXY(0,2)] + a[getXY(1,1)] + a[getXY(2,0)];
            for(int i=1; i<=cnt; i++){
                for(int j = i+1; j<=cnt; j++){
                    if(sum[i]!=sum[j]) return false;
                }
            }
            return true;
        }

        private int getDistance(int[] a, int[][] b){
            int total = 0;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    total += Math.abs(a[getXY(i,j)]-b[i][j]);
                }
            }
            return total;
        }
        private void Try(int id, int[][] s){
            if(id==9){
                if(check(x) == false ) return;
                if(getDistance(x,s) == 12) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            System.out.print(x[getXY(i, j)]);
                            System.out.print(" ");
                        }
                        System.out.print('\n');
                    }
                    System.out.print('\n');
                }
                res = Math.min(res,getDistance(x,s));
            }
            for(int i = 1; i <= 9; i++){
                if(mark[i] == false){
                    mark[i] = true;
                    x[id]=i;
                    Try(id+1, s);
                    mark[i] = false;
                }
            }
        }

        public int getXY(int i,int j){
            return i*3+j;
        }
        public int formingMagicSquare(int[][] s) {
            Try(0,s);
            return res;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int[][] s = new int[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                s[i][j] = sc.nextInt();
            }
        }
        Solver solver = new Solver();
        int result = solver.formingMagicSquare(s);
        System.out.println(result);
    }
}
