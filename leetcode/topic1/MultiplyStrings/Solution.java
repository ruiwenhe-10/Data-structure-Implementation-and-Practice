import java.util.Arrays;
class Solution {
    public static String multiply(String num1, String num2) {
        int num1_len = num1.length();
        int num2_len = num2.length();
        int[] result = new int[num1_len+num2_len];
        for (int i = num1_len-1; i >=0; i--) {
            for (int j = num2_len-1; j >=0; j--) {
                int num_2 = num2.charAt(j) - '0';
                int num_1 = num1.charAt(i) - '0';
                result[j+i+1] += num_2*num_1;
                // System.out.println(num_1+ " " + num_2);
            }
        }
        int carry = 0;
        for (int i = num1_len+num2_len-1; i >= 0; i--) {
            int sum = carry + result[i];
            carry = sum/10;
            result[i] = sum%10;
        }
        StringBuilder string_result = new StringBuilder();
        for (int a : result) string_result.append(a);
        
        while(string_result.length()!=0 && string_result.charAt(0)=='0') {string_result.deleteCharAt(0);}
        return string_result.length()==0 ? "0" : string_result.toString();
    }
 

    
    public static void main(String[] args) {
        System.out.println(multiply("123","456"));
    }
}