using namespace std;
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>


string convert(string s, int numRows);


int main() {
    
    // string  a = "";
    // a = a+'a';
    // cout << a << endl;
    cout << convert("PAYPALISHIRING",3) << endl;
    
    return 0;
}


string convert(string s, int numRows) {
    if(s.size()<=numRows) { return s;}
    vector<string> nums(numRows,"");
    int i = 0, size = s.size(), row_index = 0;
    while(i < size) {
        while(row_index < numRows && i < size) {
            nums.at(row_index++).push_back(s[i++]);
        }
        row_index -= 2;
        while(row_index >= 1 && i < size) {
            nums.at(row_index--).push_back(s[i++]);
        }
    }
    string result = "";
    for (string a : nums) {result+=a;}
    return result;
}

