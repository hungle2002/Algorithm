#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int lIS(int arr[], int n){
  int* dp = new int[n+1];
  dp[0] = 1;
  for(int i=1; i<n; i++){
    dp[i] = 0;
    for(int j=0; j<i; j++){
      if(arr[i] > arr[j]){
      dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }
  return dp[n-1];
}
int main(){
  int arr[6] = {1, 3, 2, 8, 4, 5};
  cout << lIS(arr, 6);
}