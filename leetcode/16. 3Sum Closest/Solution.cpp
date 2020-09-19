#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h> 

using namespace std;


int threeSumClosest(vector<int>& nums, int target);
int main(int argc, char* argv[]) {
    
    
    return 0;
} 




int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int s = nums.size(), sum = nums[0]+nums[1]+nums[2];
    for (int i = 0; i < s; ++i) {
        int l = i+1, r = s-1;
        if(i!=0 && nums[i]==nums[i-1]) continue;
        while(l < r) {
            int temp = nums[l]+nums[r]+nums[i];
            if(abs(sum-target)>abs(temp-target)) {
                    sum = nums[l]+nums[r]+nums[i];
            }
            if(temp>target) {
                r--;
            }
            else if(temp < target) {
                l++;
            }
            else {
                return target;                
            }
        }
    }
    return sum;    
}