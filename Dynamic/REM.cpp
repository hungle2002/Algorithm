#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
// regular expression matching
// link: https://redquark.org/leetcode/0010-regular-expression-matching/
bool isMatch(string s, string p) {
    if(s.size() == 0 && p.size() == 0){
        return 1;
    }
    if(p.size() == 0){
        return 0;
    }
    int dp[100][100]{0};
    dp[0][0]=1;
    // check pattern for empty string
    for(int i=1; i<=p.size(); i++){
        if(p[i-1] == '*'){
            dp[0][i] = dp[0][i-2];
        }
    }
    // common case
    for(int i=1; i<=s.size(); i++){
        for(int j=1; j<=p.size(); j++){
            if(p[j-1] == '*'){
                // precede char of * equal current char
                if(p[j-2] == s[i-1] || p[j-2] == '.'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-2];
                }else{
                    dp[i][j] = dp[i][j-2];
                }
            }else if(p[j-1] == '.' || s[i-1] == p[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    for(int i=0; i<=s.size(); i++){
        for(int j=0; j<=p.size(); j++){
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
    return dp[s.size()][p.size()];
}
int main(){
    cout << isMatch("aab", "c*a*b");
}
