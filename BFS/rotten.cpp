#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct fruit{
    int x,y;
    fruit(int a, int b){
        this->x=a;
        this->y=b;
    }
};
int col[4]{-1, 1, 0, 0};
int row[4]{0, 0, -1, 1};
int secondsToBeRotten(vector<vector<int>>& grid) {
    int  unrot=0;
    unsigned int n = grid.size();
    unsigned int m = grid[0].size();
    queue<fruit> q;

    for( unsigned int i=0; i<n; i++){
        for( unsigned int j=0; j< m; j++){
            if(grid[i][j] == 2){
                fruit tmp(i, j);
                q.push(tmp);
                }
            if(grid[i][j] == 1){
                unrot++;
                }
        }
    }

    // if( rot == m*n) return 0;

    int time=0;
    queue<fruit> q2;
    queue<fruit> q3; // empty queue
    q2 = q;
    while(q2.size()){
    q2 = q3; // gan q2 bang rong
     while(q.size()){
        fruit first = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            unsigned int r = first.x + col[i];
            unsigned int c = first.y + row[i];
            if(r >= 0 && c >= 0 && r< n && c < m){
                if(grid[r][c] == 1){
                    unrot--;
                    grid[r][c] = 2;
                    fruit tmp(r, c);
                    q2.push(tmp);
                }
            }
        }

        }
        cout << q2.size()<<endl;
        q = q2;
        time++;
        if(unrot == 0) return time;
    }
    return -1;
}
int main(){
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cin >> grid[i][j];
    }
    cout << secondsToBeRotten(grid);
}