import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.ListIterator;
class Solution {
    public static List<Integer> addToArrayForm(int[] A, int K) {
        List<Integer> result = new ArrayList();
        for (int num:A) {result.add(num);}
        int len = A.length - 1;
        // int carry = K;       make k carry!!!!
        while(len>=0 && K>0) {
            int sum = result.get(len) + K;
            K = sum/10;
            result.set(len,sum%10);
            len--;
        }
        while(K>0) {
            result.add(0,K%10);
            K = (K-K%10)/10;
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        int[] num = {1,2,3};
        System.out.println(addToArrayForm(num, 345));
    }
}