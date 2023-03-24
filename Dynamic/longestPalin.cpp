#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int longestPalindrome(string s) {
    bool arr[1000][1000]{0};
    int maxL = 1;
    // int x=0;
    for(int i=0; i<s.size(); i++){
        for(int j = 0; j<s.size(); j++){
            if(i==0)arr[j][j+i] = 1;
            else{
                if(s[j] == s[j+i]){
                    if(i == 1 || arr[j+1][j+i-1]){
                        arr[j][j+i] = 1;
                        maxL = max(maxL, i+1);
                        // x=j;
                    }
                }
            }
        }
    }
    // for(int i=0; i<s.size(); i++){
    //     for(int j=i; j<s.size(); j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return maxL;
}
int main(){
    string s = "abbcaac";
    cout << longestPalindrome(s);
}


// 1 2    1 3
// 2 3    2 4
// 3 4    3 5