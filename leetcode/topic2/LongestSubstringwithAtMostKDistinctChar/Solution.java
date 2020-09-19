import java.util.TreeMap;
import java.util.Random;
import java.util.HashMap;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.Map;

class Solution {
    // public static int lengthOfLongestSubstringKDistinct(String s, int k) {
    //     // if(s.length()==1) {return 1;}
    //     int maxLen = 0;
    //     HashMap<Character,Integer> letter = new HashMap<>();
    //     int i = 0, j = 0;
    //     int str_len = s.length();
    //     while (j < str_len) {
    //         if (letter.size() < k+1) {letter.put(s.charAt(j), j);}
    //         if (letter.size() == k+1) {
    //             int reIndex = Collections.min(letter.values());
    //             i = reIndex+1;
    //             letter.remove(s.charAt(reIndex));
    //         }
    //         maxLen = Math.max(maxLen,j-i+1);
    //         j++;
    //     }
    //     return maxLen;
    // }
    
    // ************************************************************************************************************************
    // ************************************************************************************************************************
    // version 2
    
    // public static int lengthOfLongestSubstringKDistinct(String s, int k) {
    //     LinkedHashMap<Character, Integer> letter = new LinkedHashMap<>();
    //     int left = 0,right = 0,maxLen = 0;
    //     int len = s.length();
    //     while(right < len && k!=0) {
    //         Character target = s.charAt(right);
    //         if (letter.containsKey(target)) {letter.remove(target);}
    //         letter.put(target,right);
    //         if (letter.size() == k+1) {
    //             Map.Entry<Character,Integer> leftmost = letter.entrySet().iterator().next();
    //             left = leftmost.getValue()+1;
    //             letter.remove(leftmost.getKey());
    //         }
    //         maxLen = Math.max(maxLen,right - left + 1);
    //         right++;
    //     }
    //     return maxLen;
        
    // }
    
    // ************************************************************************************************************************
    // ************************************************************************************************************************
    // version 3
    public static int lengthOfLongestSubstringKDistinct(String s, int k) {
        if(k ==0) return 0;
        HashMap<Character, Integer> letter = new HashMap<>();
        int right = 0,left = 0,distinct = 0,maxLen = 0;
        while (right < s.length()) {
            Character target = s.charAt(right);
            if(letter.containsKey(target)) {
                if (letter.get(target)==0) {distinct++;}
                letter.put(target,letter.get(target)+1);
            }
            else {letter.put(target,1); distinct++;}
            while(distinct>k) {
                Character leftmost = s.charAt(left);
                letter.put(leftmost,letter.get(leftmost)-1);
                left++;
                if (letter.get(leftmost)==0) {distinct--;}
            }
            maxLen = Math.max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
    
    
    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstringKDistinct("abcabcabc",2));
    }
}