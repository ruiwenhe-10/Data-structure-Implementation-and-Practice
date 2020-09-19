import java.util.Arrays;
import java.util.List;
import java.util.LinkedList;

class Solution {
    public static List<String> letterCombinations(String digits) {
        LinkedList<String> res = new LinkedList<String>();
        if(digits.length() == 0) {return res;}
        String[] mapping = new String[] {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.add("");
        for (int i = 0; i < digits.length(); ++i) {
            int digit = Character.getNumericValue(digits.charAt(i));
            if(digit < 2||digit>9) {return new LinkedList<String>();}
            while(i==res.peek().length()) {
                String prev = res.remove();
                for (char a : mapping[digit-2].toCharArray()) {
                    res.add(prev+a);
                }
            }
            
        }
        
        return res;
    }   
    
    public static void main(String[] args) {
        
        // String a = "97 1234 ";
        // char b = 97;
        
        // System.out.println((Character.getNumericValue(args[0].charAt(0))-2)*3+97);   
        // for (int i = 97+(Integer.parse), i < )
        // System.out.println(a+b);
        // System.out.println(String.valueOf(b));
        System.out.println(Arrays.toString(letterCombinations(args[0]).toArray()));
        
        
        return;
    }

}