import java.util.Arrays;
class Solution {
    public static int[] plusOne(int[] digits) {
        int len = digits.length;
        int carry = (digits[len-1] + 1)/10;
        digits[len-1] = (digits[len-1] + 1)%10;
        for (int i = len-2; i>=0 && carry>0; i--) {
            int sum = carry + digits[i];
            carry = sum/10;
            digits[i] = sum%10;
        }
        if(carry>0) {
            int[] result = new int[len+1];
            result[0] = carry;
            for (int i = 0; i < len; i++) {
                result[i+1] = digits[i];
            }
            return result;
        }
        return digits;    
    }
    
    // public static int[] plusOne(int[] digits) {
        
    // int n = digits.length;
    // for(int i=n-1; i>=0; i--) {
    //     if(digits[i] < 9) {
    //         digits[i]++;
    //         return digits;
    //     }
        
    //     digits[i] = 0;
    // }
    
    // int[] newNumber = new int [n+1];
    // newNumber[0] = 1;
    
    // return newNumber;
    // }

    public static void main(String[] args) {
        int[] a = {9,0,1,9};
        System.out.println(Arrays.toString(plusOne(a)));
    }
}