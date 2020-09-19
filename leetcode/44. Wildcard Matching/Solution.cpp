#include <iostream>

using namespace std;

bool isMatch(string s, string p);

int main(int argc, char *args[]) {
    cout << "result: " << isMatch("acdcb","*a*c?b") << endl;;
    return 0;
}


bool isMatch(string s, string p) {
    int m = p.size();
    int n = s.size();
    bool dp[m+1][n+1];
    for (int i = 0; i < m+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            dp[i][j] = false; 
        }
    }
    dp[0][0] = true;
    for(int i = 1; i < m+1; ++i) {
        if(p[i-1]=='*') { dp[i][0] = dp[i-1][0];}
    }
    
    for (int i = 1; i < m+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            if(p[i-1]==s[j-1] || p[i-1]=='?') {dp[i][j] = dp[i-1][j-1];}
            else if(p[i-1]=='*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
            }
        }
    }
    
    // for (int i = 0; i < m+1; ++i) {
    //     for (int j = 0; j < n+1; ++j) {
    //       cout << dp[i][j] << ' ';
    //     }
    //     cout << ' ' << endl;
    // }
    
    return dp[m][n];
}