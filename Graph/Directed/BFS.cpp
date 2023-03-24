#include <iostream>
#include <list>
#include<queue>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};
class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        bool check[100]{0};
        queue<int>q;
        Adjacency* ans = new Adjacency();
                check[v]=1;
                q.push(v);
                while(!q.empty()){
                    int tmp=q.front();
                    ans->push(tmp);
                    q.pop();
                    for(int j=0; j<this->adj[tmp].getSize(); j++){
                        if(!check[this->adj[tmp].getElement(j)]){
                            check[this->adj[tmp].getElement(j)]=1;
                            q.push(this->adj[tmp].getElement(j));
                        }
                    }
                }
        return ans;
	}
};
int main(){
int V = 6;
int visited = 0;

Graph g(V);
Adjacency* arr = new Adjacency(V);
// int edge[][2] = {{0,1},{0,2},{1,3},{1,4},{2,4},{3,4},{3,5},{4,5}};
    
// for(int i = 0; i < 8; i++)
// {
//     g.addEdge(edge[i][0], edge[i][1]);
// }
    
	    int alo[6][6]={
{0, 1, 1, 0, 0, 0},
{0, 0, 0, 0, 1, 0},
{0, 0, 0, 1, 1, 0},
{0, 0, 0, 0, 1, 1},
{1, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0}
};
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(alo[i][j]){
                g.addEdge(i, j);
            }
        }
    }
arr = g.BFS(visited);
arr->printArray();
delete arr;
}