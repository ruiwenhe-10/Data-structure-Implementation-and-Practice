class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        return 0.0;
    }
    public static double median(int[] nums) {
        if(nums.length%2==0) {
            return (nums[nums.length/2] + nums[nums.length/2-1])/2.0;
        }
        else {
            return (double)nums[nums.length/2];
        }
    }
    
    public static void main(String args[]) {
        int[] nums = {1,2,3,4,5,6};
        System.out.println(median(nums));
    }
}