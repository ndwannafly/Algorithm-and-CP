import java.util.Scanner;

public class Solution {

    private static final Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] s = new int[k];
        for(int i=0; i<n; i++){
            int x = sc.nextInt() % k ;
            s[x]++;
        }
        int res = 0;
        for(int i=1; i<=k/2; i++){
            if(i*2==k) {
                res++;
                break;
            }
            res+=Math.max( s[i], s[k-i]);
        }
        if(s[0] > 0) ++res;
        System.out.println(Math.max(res,1));
    }
}
