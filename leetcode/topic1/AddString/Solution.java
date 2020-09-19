class Solution {
    public static String addStrings(String num1, String num2) {
        int len_1 = num1.length()-1;
        int len_2 = num2.length()-1;
        StringBuilder res = new StringBuilder();
        int carry = 0;
        while(len_1>=0||len_2>=0) {
            int num_1 = (len_1>=0) ? num1.charAt(len_1)-'0':0;
            int num_2 = (len_2>=0) ? num2.charAt(len_2)-'0':0;
            int sum = num_1+num_2+carry;
            res.append(sum%10);
            carry = sum/10;
            len_1--;
            len_2--;
            
        }
        if(carry>0) {res.append(carry);}
        return res.reverse().toString();
    }
    
    public static void main(String[] args) {
        System.out.println(addStrings("1","999999999"));
    }
}