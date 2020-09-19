#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void readData(const string &filename, vector<double> &angles, vector<double> &coefficients) {
    double a = 0.0;
    double b = 0.0;
    ifstream inFS;
    inFS.open(filename.c_str());
    if(!inFS.is_open()) {
        cout << "Error opening" << ' ' << filename << endl;
        exit(1);
    }
        while (inFS >> a >> b) {
        angles.push_back(a);
        coefficients.push_back(b);
        }
    inFS.close();
    return;
}

double interpolation(double anglesNum, const vector<double> &angles, const vector<double> &coefficients) {
    double coefficientsNum = 0.0;
    int position;
    bool anglesNumMatch = false;
    for (unsigned i = 0; i < angles.size(); ++i) {
            if (anglesNum == angles.at(i)) {
                coefficientsNum = coefficients.at(i);
                anglesNumMatch = true;
            }
    }
    while (!anglesNumMatch) {
            position = 0;
            while (angles.at(position) < anglesNum) {
                ++position;
            }
            
            coefficientsNum = coefficients.at(position - 1) + (anglesNum - angles.at(position - 1))/(angles.at(position) - angles.at(position - 1)) * (coefficients.at(position) - coefficients.at(position - 1));
            anglesNumMatch = true;
    }
    
    
    return coefficientsNum;
}


bool isOrdered(const vector<double> &angles) {
    int number = 0;
    unsigned int i = 0;
    bool order = false; 
    for (i = 0; i + 1 < angles.size(); ++i) {
        if (angles.at(i) > angles.at(i + 1)) {
            ++number;
        }
    }
    if (number >= 1) {
        order = false;
    }
    else {
        order = true;
    }
    return order;
}
void reorder(vector<double> &angles, vector<double> &coefficients) {
   unsigned int i = 0;
   unsigned int a = 0;
   double tem1 = 0.0;
   double tem2 = 0.0;
   for (a = 0; a + 1 < angles.size(); ++a){
        for (i = 0; i + 1 < angles.size(); ++i) {
            if (angles.at(i) > angles.at(i + 1)) {
            tem1 = angles.at(i);
            angles.at(i) = angles.at(i + 1);
            angles.at(i + 1) = tem1;
            tem2 = coefficients.at(i);
            coefficients.at(i) = coefficients.at(i + 1);
            coefficients.at(i + 1) = tem2;
            }
        }
    }
    return;
}




int main() {
    vector<double> angles;
    vector<double> coefficients;
    double anglesNum;
    string filename;
    string answer;
    cout << "Enter name of input data file:" << endl << endl;
    cin >> filename;
    readData(filename, angles, coefficients);
    cout << "Enter angles number:" << endl;
    cin >> anglesNum;
    cout << interpolation(anglesNum, angles, coefficients) << endl;
    cout << "Enter anthor angles number?" << endl;
    cin >> answer;
    while (answer == "yes") {
        cout << "Enter angles number:" << endl;
        cin >> anglesNum;
        cout << interpolation(anglesNum, angles, coefficients) << endl;
        cout << "Enter anthor angles number?" << endl;
        cin >> answer;
    }
    
    
   
  
    
    
    
return 0;
}