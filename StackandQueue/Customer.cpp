#include <bits/stdc++.h>

using namespace std;
struct customer{
	int atime;
	int ctime;
	customer(int a, int b){
		atime=a;
		ctime=b;
	}
};
struct compare
{
	bool operator()(customer &a, customer &b){
		return a.ctime>b.ctime;
	}
};
bool sosanh(customer &a, customer &b){
	return a.atime>b.atime;
}
int solve(int n, vector<customer>vec){
	priority_queue<customer, vector<customer>, compare>pq;
	sort(vec.begin(), vec.end(), sosanh);
	int currenttime=vec.back().atime;
	int mintime=0;
	for(int i=1; i<=n; i++){
		while(!vec.empty() && vec.back().atime<=currenttime){
			pq.push(vec.back());
			vec.pop_back();
		}
		customer client=pq.top();
		pq.pop();
		int _atime=client.atime;
		int _ctime=client.ctime;
		mintime += (currenttime -_atime+_ctime);
		currenttime+=_ctime;
		if(!vec.empty() && pq.empty()){
			currenttime=max(currenttime, vec.back().atime);
		}
		//cout << currenttime<<" ";
	}
	return mintime;
}
int minWaitingTime(int n, int arrvalTime[], int completeTime[]) {
    // YOUR CODE HERE
	vector<customer>vec;
	for(int i=0;i<n; i++){
		vec.push_back(customer(arrvalTime[i], completeTime[i]));
	}
	return solve(n, vec);
}
int main(){
	int n = 4; 
int arrvalTime[] = { 0, 4, 2, 5};
int completeTime[] = { 4, 2, 3, 4};
cout << minWaitingTime(n, arrvalTime, completeTime);
}