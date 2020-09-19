
class Solution {
    
    public static int trap(int[] height) {
        int left = 0, right = height.length-1, left_bound = 0, right_bound = 0, area = 0;
        while(left<=right) {
            if(height[left] < height[right]) {
                if(height[left] > left_bound) {
                    left_bound = height[left];
                }
                else {
                    area += left_bound - height[left];   
                }
                left++;
            }
            else {
                if(height[right] > right_bound) {
                    right_bound = height[right];
                }
                else {
                    area += right_bound-height[right];
                }
                right--;
            }
        }
        return area;
    }
    
    
    public static void main(String args[]) {
        
        int[] a = {1,3,1,2,3};
        // System.out.println(a);
        System.out.println(trap(a));
        
        return;
    }
}