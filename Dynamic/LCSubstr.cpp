#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<unordered_map>
#include<sstream>
using namespace std;
// Maximum Length of Repeated Subarray
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int dp[n][m];
        dp[0][0] = nums1[0]==nums2[0]?1:0;
        int ans = dp[0][0];
        for(int i=1;i<n;i++){
            dp[i][0] = nums1[i]==nums2[0]?1:0;
            ans = max(ans, dp[i][0]);
        }
        for(int i=1;i<m;i++){
            dp[0][i] = nums1[0]==nums2[i]?1:0;
            ans = max(ans, dp[0][i]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(nums1[i]==nums2[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    for(int i=0; i<nums1.size(); i++){
        for(int j=0; j<nums2.size(); j++){
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
        return ans;
    }
int main(){
    vector<int>num1{0,0,0,0,0,0,1,0,0,0};
    vector<int>num2{0,0,0,0,0,0,0,1,0,0};
    cout << findLength(num1, num2);
}


