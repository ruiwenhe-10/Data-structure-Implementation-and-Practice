#include<iostream>

using namespace std;


// int gcd(int inNum1, int inNum2) {
//   int gcdVal = 0; // Holds GCD results
   
//   if(inNum1 == inNum2) {    // Base case: Numbers are equal
//       gcdVal = inNum1;       // Return value
//   }
//   else {                    // Recursive case: subtract smaller from larger
//       if (inNum1 > inNum2) { // Call function with new values
//          gcdVal = gcd(inNum1 - inNum2, inNum2);
//       }
//       else {
//          gcdVal= gcd(inNum1, inNum2 - inNum1);
//       }
//   }
   
//   return gcdVal;
// }                                                abosulte value
int gcd(int a, int b) {
    if (a % b == 0){
        return b;
    }
    int x = a % b;
    return gcd(b, x);
    
    
}
// If gcd(a,b) does not divide c, then there is no solution.

// If b divides a (the remainder of a / b is 0), then you can just divide by b to get the solution: x = 0, y = c / b.

// Otherwise (b does not divide a), through a substitution method, we can come up with a simpler version of the original problem and solve the simpler problem using recursion.

bool diophantine(int a, int b, int c, int &x, int &y) {
  if (c % gcd(a,b) != 0) {
      return false;
  }
  else if (a % b == 0) {
      x = 0;
      y = c / b;
      return true;
  }
  else {
      int q = a / b;
      int r = a % b;
      int u = q * x + y;
      int v = x;
      diophantine(b, r, c, u, v);
      x = v;
      y = u - q * x;
      return true;
      }
  }







int main() {

    int a, b, c, x, y;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}