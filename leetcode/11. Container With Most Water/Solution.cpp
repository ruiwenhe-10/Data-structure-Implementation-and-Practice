#include <iostream>
#include <vector>
#include <algorithm> 


using namespace std;

int maxArea(vector<int>& height);

int main(int argc, char* argv[]) {
    
    vector<int> a = {1,8,6,2,5,4,8,3,7};
    
    cout << maxArea(a) << endl;
    
    return 0;
}


int maxArea(vector<int>& height) {
    int left = 0, right =height.size()-1, area = min(height[0],height[height.size()-1]) * (height.size()-1);
    while(left < right) {
        if (height[left] < height[right]) {
            area = max(area, static_cast<int>(min(height[++left],height[right])*(right-left)));
        }
        else {
            area = max(area, static_cast<int>(min(height[left],height[--right])*(right-left)));
        }
    }
    return area;
}