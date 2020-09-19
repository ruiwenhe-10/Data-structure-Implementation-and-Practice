#include <iostream>
#include <stdlib.h>

using namespace std;



 string intToRoman(int num);
 string repeat(string a, int num);
 string sub_output(int num, string five, string one);
 
 int main(int argc, char* agrv[]) {
    //  cout << repeat("abc",3) << endl;
     cout << intToRoman(atoi(agrv[1])) << endl;
     return 0;
 }
 
//  Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
 
 string repeat(string a, int num) {
     string res = "";
     for (int i = 0; i < num; ++i) {
         res += a;
     }
     return res;
 }
 
 string sub_output(int &num, int target, string ten, string five, string one) {
    string res = "";
    while(num>=target) {
         int lead = num/target;
         if(lead == 9) {
             res += one + ten;
         }
         else if(lead >= 5) {
             res += five + repeat(one,lead-5);
         }
         else if(lead==4) {
             res += one+five;
         }
         else {
             res += repeat(one,lead);
         }
         num-=lead*target;
     }
     return res;
 }
     
 
 string intToRoman(int num) {
     string res = "";
     while(num>=1000) {
         int lead = num/1000;
         res +=  repeat("M",lead);
         num -= lead*1000;
     }
     res += sub_output(num,100,"M","D","C");
     res += sub_output(num,10,"C","L","X");
     res += sub_output(num,1,"X","V","I");
     
     return res;
 }
 
 
 