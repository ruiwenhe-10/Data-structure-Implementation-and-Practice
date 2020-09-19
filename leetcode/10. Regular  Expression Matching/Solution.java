import java.util.Arrays;

public class Solution {
    public static void main(String[] args) {
        System.out.println(isMatch("abcd",".a*b*cd"));
        
    }
    
    public static boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[p.length()+1][s.length()+1];
        
        //initialization
        dp[0][0]=true;
        for (int i = 1; i < p.length()+1; ++i) {
            if(p.charAt(i-1) == '*') {
                if(i-2>=0) { dp[i][0] = dp[i-2][0];}
                else {dp[i][0] = true;}
            }
        }
        // for (int i = 0; i < p.length()+1; ++i) {     // test initialization
        //     System.out.println(dp[i][0]);
        // }
        // System.out.println();
        
        for (int i = 1; i < p.length()+1; ++i) {
            for (int j = 1; j < s.length()+1; ++j) {
                if(p.charAt(i-1) == '.' || p.charAt(i-1) == s.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                    // System.out.println(dp[i][j]);
                    // return true;
                }
                else if(p.charAt(i-1) == '*') {
                    if(p.charAt(i-2)==s.charAt(j-1)||p.charAt(i-2)=='.') {dp[i][j]=dp[i][j-1]||dp[i-2][j];}
                    else {dp[i][j] = dp[i-2][j];}
                }
            }
        }
        
        // for (int i = 0; i < p.length()+1; ++i) {
        //     for (int j = 0; j < s.length()+1; ++j) {
        //         System.out.print(dp[i][j]);
        //         System.out.print(' ');
        //     }
        //     System.out.println();
        // }
        
        
        return dp[p.length()][s.length()];
    }
    
}