#include <iostream>
#include <list>
#include <stack>
#include<vector>
#include<queue>
using namespace std;
struct pos{
int x,y;
pos(int _x, int _y){
    x=_x; y=_y;
}
};
void printMatrix(vector<vector<int>>& matrix){
      int max_i=matrix.size();
    int max_j=matrix[0].size();  
    for(int i=0; i<max_i; i++){
        for(int j=0; j<max_j; j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

vector<vector<int>> onTheSand(vector<vector<int>>& matrix) {
    // STUDENT ANSWER
    int max_i=matrix.size();
    int max_j=matrix[0].size();

    for(int i=0; i<max_i; i++){
        for(int j=0; j<max_j; j++){
            if(matrix[i][j]){
                matrix[i][j]=INT_MAX;
            }
        }
    }
    int row[4]={-1,  0, 0, 1};
    int col[4]={ 0, -1, 1, 0};
    queue<pos>q;
    for(int i=0; i<max_i; i++){
        for(int j=0; j<max_j; j++){

            if(!matrix[i][j]){
                q.push(pos(i,j));
                while(!q.empty()){
                    pos tmp = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int x1=tmp.x+row[k];
                        int y1=tmp.y+col[k];
                        if(x1>=0 && y1>=0 &&x1<max_i && y1<max_j && matrix[x1][y1]>0 && matrix[x1][y1]>matrix[tmp.x][tmp.y]+1){
                            q.push(pos(x1, y1));
                            matrix[x1][y1] = matrix[tmp.x][tmp.y]+1;
                        }
                    }
                }
            }

        }
    }
    return matrix;
}
int main(){
vector<vector<int>> matrix {
	{1, 1, 1},
	{1, 1, 1},
	{0, 1, 0}
};
auto res = onTheSand(matrix);
printMatrix(res);
}
