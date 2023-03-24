#include<iostream>
using namespace std;
int findmin(int dist[], bool check[]){
    int min=INT_MAX, index;
    for(int i=0; i<6; i++){
        if(!check[i] && dist[i]<=min){
            min=dist[i];
            index=i;
        }
    }
    return index;
}
int Dijkstra(int** graph, int src, int dst) {
	// TODO: return the length of shortest path from src to dst.
	bool check[6]{0};
    int dist[6];
    for(int i=0; i<6; i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int i=0; i<6; i++){
        int u= findmin(dist, check);
        check[u]=1;
        // cap nhat
        for(int j=0; j<6; j++){
            if(!check[j] && graph[u][j] && dist[u]!=INT_MAX && dist[u]+graph[u][j]<dist[j]){
                dist[j] = dist[u]+graph[u][j];
            }
        }
    }
    return dist[dst];
}
int main(){
int n = 6;
int init[6][6] = {
	{0, 10, 20, 0, 0, 0},
	{10, 0, 0, 50, 10, 0},
	{20, 0, 0, 20, 33, 0},
	{0, 50, 20, 0, 20, 2},
	{0, 10, 33, 20, 0, 1},
	{0, 0, 0, 2, 1, 0} };

int** graph = new int*[n];
for (int i = 0; i < n; ++i) {
	graph[i] = init[i];
}

cout << Dijkstra(graph, 0, 1);
}