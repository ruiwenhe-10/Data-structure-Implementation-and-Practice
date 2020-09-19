import java.util.TreeMap;
import java.util.Random;
import java.util.HashMap;
import java.util.Collections;

class Solution {
    public static int lengthOfLongestSubstringTwoDistinct(String s) {
        int maxLen = 0;
        HashMap<Character,Integer> letter = new HashMap<>();
        int i = 0, j = 0;
        int str_len = s.length();
        while (j < str_len) {
            if (letter.size() < 3) {letter.put(s.charAt(j), j);}
            if (letter.size() == 3) {
                int reIndex = Collections.min(letter.values());
                i = reIndex+1;
                letter.remove(s.charAt(reIndex));
            }
            maxLen = Math.max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
    
    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstringTwoDistinct("a"));
    }
}