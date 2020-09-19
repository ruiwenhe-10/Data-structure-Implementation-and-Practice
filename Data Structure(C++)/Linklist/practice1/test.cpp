#include "IntList.h"

#include <iostream>
using namespace std;

int main() {
    IntList list5;

 cout << "\npushfront 10";
      list5.push_front( 10 );
      cout << "\npushfront 20";
      list5.push_front( 20 );
      cout << "\npushfront 10";
      list5.push_front( 10 );
      cout << "\npushfront 30";
      list5.push_front( 30 );
      cout << "\nlist5: ";
      list5.display();
      cout << "\nremove_duplicates()";
      list5.remove_duplicates();
      cout << list5;
      cout << endl;
    
    
    return 0;
}