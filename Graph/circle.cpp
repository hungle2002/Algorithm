#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int findparent(int parent[], int x){
    if(parent[x]==-1){
        return x;
    }
    return findparent(parent, parent[x]);
}
void merge(int parent[], int x, int y){
    parent[x]=y;
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    int * parent = new int[n];
    memset(parent, -1, n*sizeof(int));
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(isConnected[i][j]){
                int pi = findparent(parent, i);
                int pj = findparent(parent, j);
                if(pi!=pj){
                    merge(parent, pi, pj);
                }
            }
        }
    }   
    int count=0;     
    for(int i=0; i<n; i++){
        if(parent[i]==-1){
            count++;
        }
    }
    return count;
}
int main(){
    vector<vector<int>>isConnected={{0, 1, 1, 0, 1, 0},
                                    {1, 0, 0, 1, 1, 0},
                                    {1, 0, 0, 1, 1, 0},
                                    {0, 1, 1, 0, 1, 0},
                                    {1, 1, 1, 1, 0, 0},
                                    {0, 0, 0, 0, 0, 0}};
    cout << findCircleNum(isConnected);
}