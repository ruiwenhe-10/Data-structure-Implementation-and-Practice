#include<iostream>
#include<string>
#include <cctype>
using namespace std;


#include "Date.h"









bool Date::isLeap(unsigned y) const {
   bool leap = false;
   if((y % 4 == 0) && !(y % 100 == 0)) {
      leap = true;
    }
    else if(y % 400 == 0){
      leap = true;
    }
    else {
      leap = false;       
    }
   return leap;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   int day = 0;
   if (m == 2) {
      if(isLeap(y)) {
         day = 29;
      }
      else {
         day = 28;
      }
   }
   else {
      if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
      day = 31;  
      }
      else if (m == 2 || m == 4 || m == 6 || m == 9 || m == 11) {
      day = 30;
      }
   }   
   return day;
}
string Date::name(unsigned m) const {
   string month;
   if (m == 1) {
      month = "January";
   }
   if (m == 2) {
      month = "February";
   }
   if (m == 3) {
      month = "March";
   }
   if (m == 4) {
      month = "April";
   }
   if (m == 5) {
      month = "May";
   }
   if (m == 6) {
      month = "June";
   }
   if (m == 7) {
      month = "July";
   }
   if (m == 8) {
      month = "August";
   }
   if (m == 9) {
      month = "September";
   }
   if (m == 10) {
      month = "October";
   }
   if (m == 11) {
      month = "November";
   }
   if (m == 12) {
      month = "December";
   }
    return month;
}

unsigned Date::number(const string &mn) const {
   string a = mn;
   a.at(0) = static_cast<char>(toupper(a.at(0)));
   int month;
   if (a == "January") {
      month = 1;
   }
   if (a == "February") {
      month = 2;
   }
   if (a == "March") {
      month = 3;
   }
   if (a == "April") {
      month = 4;
   }
   if (a == "May") {
      month = 5;
   }
   if (a == "June") {
      month = 6;
   }
   if (a == "July") {
      month = 7;
   }
   if (a == "August") {
      month = 8;
   }
   if (a == "September") {
      month = 9;
   }
   if (a == "October") {
      month = 10;
   }
   if (a == "November") {
      month = 11;
   }
   if (a == "December") {
      month = 12;
   }
    return month;
}


Date::Date() {
   monthName = "January";
   day = 1;
   year = 2000;
   month = 1;
}

Date::Date(unsigned m, unsigned d, unsigned y) {
   monthName = name(m);
   year = y;
   bool error = false;
   if (m >= 1 && m <= 12) {
      month = m;
   }
   else if (m <= 0){
      month = 1;
      error = true;
   }
   else {
      month = 12;
      error = true;
   }
   if (d <= daysPerMonth(month, year) && d >= 1) {
      day = d;
   }
   else if (d <= 0) {
      day = 1;
   }
   else {
      day = daysPerMonth(month, year);
      error = true;
   }
   if (error) {
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
   }
   else {
   }
}

Date::Date(const string &mn, unsigned d, unsigned y) {
   string a = mn;
   a.at(0) = static_cast<char>(toupper(a.at(0)));
   if (!(a == "January" || a == "February" || a == "March" || a == "April" || a == "May" || a == "June" || a == "July" || a == "August" || a == "September" || a == "October" || a == "November" || a == "December")) {
     cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
     monthName = "January";
     month = 1;
     day = 1;
     year = 2000;
   }
   else {
   year = y;
   monthName = a;
   month = number(a);
      if (d <= daysPerMonth(month, y) && d >= 1) {
      day = d;
      }
      else if (d <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }
      else {
      day = daysPerMonth(month, y);
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }
   }
}

void Date::printNumeric() const {
   cout << month << '/' << day << '/' << year;
   return;
}

void Date::printAlpha() const {    //March 1, 2012
   cout << name(month) << ' ' << day << ", " << year;
   return;
}
   
      
      