#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int knapsack(int w[], int v[], int n, int S){
    int dp[100][100]{0};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=S; j++){
            // do not get item i
            dp[i][j] = dp[i-1][j];
            // get item i
            if(j>=w[i-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);
            }
        }
    }
    return dp[n][S];
}
int main(){
  int w[4] = {2, 1, 4, 3};
  int v[4] = {3, 3, 4, 2};
  cout << knapsack(w, v, 4, 6);
}