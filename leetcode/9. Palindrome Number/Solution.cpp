#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool isPalindrome(int x); 

int main(int argc, char *argv[]) {
    
    cout << isPalindrome(121) << endl;
    
    return 0;
}

// bool isPalindrome(int x) {
//     if(x<0) {return false;}
//     if(x/10==0) {return true;}
//     vector<int> nums;
//     int old_val;
//     while(x>0) {
//         nums.push_back(x%10);
//         x/=10;
//     }
//     int i=0, j = nums.size()-1;
//     while(i<j) {
//         if(nums.at(i++)!=nums.at(j--)) {return false;}
//     }
//     return true;
// }

public boolean isPalindrome(int x) {
    if (x<0 || (x!=0 && x%10==0)) return false;
    int rev = 0;
    while (x>rev){
    	rev = rev*10 + x%10;
    	x = x/10;
    }
    return (x==rev || x==rev/10);   //check even and odd number
}
