import java.util.Scanner;

public class solution {
    private static int n;
    private static class Solver{
        private long[][] a = new long[101][101];

        private boolean check (int x, int y){
            long sumR = 0;
            long sumC = 0;
            for(int i=0 ; i < n ; i++){
                if(i!=x) sumC += a[i][y];
                if(i!=y) sumR += a[x][i];
            }
            return sumC == sumR;
        }

        private void swap(int x, int y){
            for(int i = 0; i < n; i++){
                long tmp = a[x][i];
                a[x][i] = a[y][i];
                a[y][i] = tmp;
            }
        }

        public boolean solve(){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            for(int i = 0 ; i < n ; i++){
                int cur = -1;
                for(int j = 0 ; j < n ; j++) if(check(i,j)) cur = j ;
                if(cur == -1 ) return false;
                swap(i,cur);
                int rowX = i, rowY = i+1;
                int colX = i+1, colY = i;
                while(rowX < n && rowY < n && colX < n && colY <n){
                    long p = a[rowX][rowY];
                    long q = a[colX][colY];
                    long t = Math.min(p,q);
                    a[rowX][rowY] -= t;
                    a[colX][colY] -= t;
                    a[colX][rowY] += t;
                    a[rowX][colY] += t;
                    if(a[rowX][rowY] == 0 ) ++rowY;
                    if(a[colX][colY] == 0 ) ++colX;
                }
            }
            return true;
        }
    }

    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int q = sc.nextInt();
        Solver solver = new Solver();
        while(q-->0){
            n = sc.nextInt();
            if(solver.solve()){
                System.out.println("Possible");
            }
            else System.out.println("Impossible");
        }
    }
}
