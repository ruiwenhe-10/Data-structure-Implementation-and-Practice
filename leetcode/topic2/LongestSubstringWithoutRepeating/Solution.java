import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;
import java.lang.Math;

class Solution {
    // public static int lengthOfLongestSubstring(String s) {
    //     Set<Character> letter = new HashSet<>();
    //     int len = s.length();
    //     int maxSize = 0;
    //     for (int i = 0; i < len; i++) {
    //         int count = 0;
    //         for (int j = i; j < len; j++) {
    //             Character chars = s.charAt(j);
    //             if(letter.contains(chars)){
    //                 j = len;
    //             }
    //             else {
    //                 letter.add(chars);
    //                 count++;
    //             }
    //         }
    //         letter.clear();
    //         maxSize = (count>maxSize)? count:maxSize;
    //     }
    //     return maxSize;
        
    // }
    
    public static int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> letter = new HashMap<>();
        int len = s.length();
        int maxLen = 0;
        for(int i=0, j=0; j < len; j++) {
            if(letter.containsKey(s.charAt(j))) {
                i = Math.max(i, letter.get(s.charAt(j))+1);
            }
            letter.put(s.charAt(j),j);
            maxLen = Math.max(maxLen, j-i+1);
        }
        return maxLen;
    }
    
    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring("pwwkew"));
    }
    
}