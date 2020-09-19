#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int threeSumSmaller(vector<int>& nums, int target);

int main(int argv, char * argc[]) {
    
    
    
    return 0;
}


int threeSumSmaller(vector<int>& nums, int target) {
    
    sort(nums.begin(),nums.ends());
    int len = nums.size(), res = 0;
    
    for (int i = 0; i < len; ++i) {
        int l = i+1, r = len-1;
        if(l<r && nums[i]>target) continue;
        while(l < r) {
            if(nums[i]+nums[l]+nums[r] < target) {
                res += r - l;
                l++;
            }
            else {
                r--;
            }
        }
        
        return res;
    }
    
    
    return 0;
}