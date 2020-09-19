#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums);



int main() {
    
    
    
    
    return 0;
}


vector<vector<int> > threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int> > res;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] >0) {return res;}
        if(i==0 || (i > 0 && nums[i] != nums[i-1])) {
            int l = i+1, r = nums.size()-1, comple = -nums[i];
            while(l < r) {
                if(nums[l]+nums[r]>comple) {
                    r--;
                }
                else if(nums[l]+nums[r]<comple) {
                    l++;
                }
                else {
                    vector<int> temp(3,0);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    while(l+1 < nums.size() && nums[l+1] == nums[l]) {
                        l++;
                    }
                    while(r-1 >= 0 && nums[r] == nums[r-1]) {
                        r--;
                    }
                    l++;
                    r--;
                }
                
            }
        }
    }
    
    
    
    return res;
}