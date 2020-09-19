class Solution {
    public String addBinary(String a, String b) {
        int len_a = a.length()-1;
        int len_b = b.length()-1;
        StringBuilder result = new StringBuilder();
        int carry = 0;
        while(len_a>=0||len_b>=0) {
            int num_a = (len_a>=0) ? a.charAt(len_a)-'0':0;
            int num_b = (len_b>=0) ? b.charAt(len_b)-'0':0;
            // System.out.print("a: " + num_a + " ");
            // System.out.println("b: " + num_b);
            int sum = carry + num_a + num_b;
            carry = sum/2;
            result.insert(0,sum%2);
            len_a--;
            len_b--;
        }
        if(carry>0) {result.insert(0,carry);}
        return result.toString();
    }

    
}