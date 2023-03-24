#include<bits/stdc++.h>
using namespace std;
struct Pair{
        long long val;
        long long ptr;
        long long product;
        Pair(){}
        Pair(long long _val,long long _ptr,long long _product){
            val=_val;
            ptr=_ptr;
            product=_product;
        }
    };
    struct compare{
        bool operator()(const Pair&a,const Pair &b){
            return a.product>b.product;
        }
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<Pair,vector<Pair>,compare>pq;
        vector<long long> dp(n+1);
        dp[1]=1;
        for(int i=0;i<primes.size();i++){
            pq.push(Pair(primes[i],1,primes[i]));
        }     
        int i=2;
        while(i<=n){
            Pair src=pq.top();pq.pop();
            if(src.product!=dp[i-1]){
                dp[i++]=src.product;
            }
            pq.push(Pair(src.val,src.ptr+1,dp[src.ptr+1]*src.val));
            
        }     
        return dp[n];
    }
int uglyNumberIndex(int n) {
    int arr[11]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    vector<int> vec;
    for(int i=0; i<11; i++){
        vec.push_back(arr[i]);
    }
return nthSuperUglyNumber(n, vec);
}
int main(){
int n = 100000;
    cout << uglyNumberIndex(n+1);
}