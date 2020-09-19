import java.util.Arrays;

public class Solution {
    public static void main(String args[]) {
        System.out.println(myAtoi("   +0 123"));
        // System.out.println(Arrays.toString(l));
    }
    
    public static int myAtoi(String str) {
        boolean sign = false;
        boolean space = true;
        int s = 1;
        int result = 0;
        for (char b : str.toCharArray()) {
            if(b!=' '){
                if(Character.isDigit(b)) {
                    int old_result = result;
                    if(result == 0) {result = Integer.parseInt(Character.toString(b));}
                    else {result = result*10 + Integer.parseInt(Character.toString(b));}
                    if(result/10 != old_result) {
                        return s==1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
                    }
                    sign = true;
                    space = false;
                }
                else {
                    if((b=='+'||b=='-')&&!sign) {
                        s = b =='-' ? -1 : 1;
                        sign = true;
                        space = false;
                    }
                    else {
                        return result*s;
                    }
                }
            }
            if(b==' '&&!space) {
                return result*s;
            }
        }
        return result*s;
    }
}