public class Solution {
    
    
    public static void main(String args[]) {
        System.out.println(reverse(Integer.parseInt(args[0])));
    }
    
    public static int reverse(int x) {
        if(x>= Math.pow(2,31)-1 || x <= -Math.pow(2,31))  {return 0;}
        int a = x>=0 ? 1 : -1;
        x = Math.abs(x);
        int result = x%10;
        x/=10;
        while(x>0) {
            int old_result = result;
            result = result*10 + x%10;
            if(result/10 != old_result) {return 0;}
            x/=10;
        }
        return result*a;
    }
}