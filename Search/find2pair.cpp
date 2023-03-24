#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
    if(n<4) return 0;
    bool visited[1000]{0};
    pair<int, int> arr_visited[1000];
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int cur_sum = arr[i] + arr[j];
            // no sum there
            if(!visited[cur_sum]){
                arr_visited[cur_sum] = pair<int, int>(arr[i], arr[j]);
                visited[cur_sum] = 1;
            }
            // visited
            else{
                // check is distinct
                if(arr_visited[cur_sum].first != arr[i] || arr_visited[cur_sum].first != arr[j]){
                    pair1 = arr_visited[cur_sum];
                    pair2.first = arr[i];
                    pair2.second = arr[j];
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    int arr[] = { 3, 4, 7, 1, 2, 9, 8 };
    int n = sizeof arr / sizeof arr[0];
    pair<int, int> pair1, pair2;
    if (findPairs(arr, n, pair1, pair2)) {
        cout << "Pair1: "<< pair1.first<<" "<<pair1.second<<endl;
        cout << "Pair2: "<< pair2.first<<" "<<pair2.second<<endl;
    }
    else printf("No pair found.\n");
}
