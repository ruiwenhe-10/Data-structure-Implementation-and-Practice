public class Solution {
    
    public static String longestPalindrome(String s) {
        String longest = "";
        for (int i = 0; i < s.length(); ++i) {
            String odd = findLongPa(s,i,i);
            String even = findLongPa(s,i,i+1);
            String temp = (odd.length() > even.length()) ? odd : even;
            longest = (longest.length() > temp.length()) ? longest : temp;
        }
        return longest;
    }
    
    public static String findLongPa(String s, int j, int k) {
        while(j>=0 && k<= s.length()-1 && s.charAt(j)==s.charAt(k)){
            j--;
            k++;
        }
        return s.substring(j+1,k);
    }
    
    public static void main(String[] args) {
        System.out.println(longestPalindrome("cbbd"));
    }
    
}