#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
// find subset have sum = S
// check all feasible sum from 0 to S can be created from array
bool subsetSum(int n, int s, int arr[]){
    bool dp[1000]{0};
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=s; j>0; j--){
            if(dp[j-arr[i]]){
                dp[j] = 1;
            }
        }
    }
}
int main(){
  int arr[4] = {2, 5, 3, 1};
  int n = 4;
  int S = 9;
  cout << subsetSum(n, S, arr);
}
// 	value	0	1	2	3	4	5	6	7	8	9
// 0		1	0	0	0	0	0	0	0	0	0
// 1	2	1	0	1	0	0	0	0	0	0	0
// 2	5	1	0	1	0	0	1	0	1	0	0
// 3	3	1	0	1	1	0	1	0	1	1	0
// 4	1	1	1	1	1	1	1	1	1	1	1
// 	S = 9										
// 	dp[i]										
// 	dp[S] True / False										
