#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
    int a[100][100]{0};
    for(int i=0; i<text1.size(); i++){
        for(int j=0; j<text2.size(); j++){
            if(text2[j] == text1[i]){
                a[i+1][j+1] = a[i][j] +1;
            }else{
                a[i+1][j+1] = max(a[i][j+1], a[i+1][j]);
            }
        }
    }
    return a[text1.size()][text2.size()];
}
int main(){
    cout << longestCommonSubsequence("adbf", "abcfadb");
}
// adbf
// abcfadb
// 		    a	b	c	f	a	d	b
// 	    0	0	0	0	0	0	0	0
// a	0	1	1	1	1	1	1	1
// d	0	1	1	1	1	1	2	2
// b	0	1	2	2	2	2	2	3
// f	0	0	0	0	0	0	0	0
