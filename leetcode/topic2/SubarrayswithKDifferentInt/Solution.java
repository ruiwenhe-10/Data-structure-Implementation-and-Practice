import java.util.HashMap;
class Solution {
    public static int subarraysWithKDistinct(int[] A, int K) {
        int left = 0, right = 0, numSub = 0, prefix = 0,distinct = 0;
        HashMap<Integer,Integer> num = new HashMap<>();
        while(right < A.length) {
            int number = A[right];
            if(!num.containsKey(number)||num.get(number)==0) {num.put(number, 1); distinct++;}
            else if (num.containsKey(number)) {num.put(number,num.get(number)+1);}
            
            if(distinct>K) {
                int temp = A[left];
                num.put(temp,num.get(temp)-1);
                distinct--;
                prefix = 0;
                left++;
            }
            while(num.get(A[left])>1) {
                num.put(A[left],num.get(A[left])-1);
                left++;
                prefix++;   
            }
            if(distinct==K) {numSub = numSub + prefix + 1;}
            right++;
        }
        
        return numSub;
    }
    
    public static void main(String[] args) {
        int[] num = {1,2,1,2,3};
        System.out.println(subarraysWithKDistinct(num,2));
    }
}