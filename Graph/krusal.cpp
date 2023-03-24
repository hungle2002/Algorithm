#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>
using namespace std;

struct Graph
{
    int V, E;
    vector< pair<int, pair<int, int>> > edges;
    // Constructor 
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({ w, {u, v} });
    }
    
    //YOUR CODE HERE
	// Some helping functions

	int kruskalMST() {
		// TODO: return weight of the minimum spanning tree.
		// create inconnected graph
		sort(edges.begin(), edges.end());
		bool visited[100]{0};
		int sum = 0;
		int count = 0;
		for(int i=0; i<E; i++){
			if(!visited[edges[i].second.first] || !visited[edges[i].second.second]){
				visited[edges[i].second.first] = 1;
				visited[edges[i].second.second] = 1;
				count++;
				sum+= edges[i].first;
				edges[i].first = -1;
			}
		}
		// connected graph
		int color[100]{0};
		int curcolor=1;
		// update color
		for(int i=0; i<E; i++){
			if(edges[i].first == -1){
				int l = edges[i].second.first;
				int r = edges[i].second.second;
				if(color[l] != 0){
					color[r] = color[l];
				}
				else if(color[r] != 0){
					color[l] = color[r];
				}
				else{
					color[l] = color[r] = curcolor;
					curcolor++;
				}
			}
		}
		//connect
		bool arr[100][100]{0};
		int color_union[100]{0};
		curcolor = 1;
		for(int i=0; i<E; i++){
			if(edges[i].first != -1){
				if(count == V-1) return sum;
				int l = edges[i].second.first;
				int r = edges[i].second.second;
				if(arr[color[l]][color[r]] == 0 && color[l] != color[r]){
					int a = color_union[color[l]];
					int b = color_union[color[r]];
					if(a ==0 && b == 0){
						color_union[color[l]]=color_union[color[r]]=curcolor;
						curcolor++;
					}
					else if(a==0){
						color_union[color[l]]=color_union[color[r]];
					}
					else if(b==0){
						color_union[color[r]]=color_union[color[l]];
					}
					else if(a==b){
						continue;
					}
					arr[color[l]][color[r]] = 1;
					arr[color[r]][color[l]] = 1;
					sum += edges[i].first;
					count++;
					cout << l<<" "<<r<< endl;
				}	
			}
		}
		return sum;
	}
};
int main(){
	int V = 8, E = 8;
	Graph g(V, E);

	g.addEdge(1, 2, 1);
	g.addEdge(3, 4, 1);
	g.addEdge(5, 6, 1);
	g.addEdge(7, 8, 1);
	g.addEdge(1, 3, 2);
	g.addEdge(4, 5, 2);
	g.addEdge(1, 5, 2);
	g.addEdge(7, 5, 3);



	cout << g.kruskalMST();
}