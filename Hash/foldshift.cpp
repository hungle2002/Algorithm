#include<iostream>
#include<string>
using namespace std;
int foldshift(long long key, int addressSize){
    int alo=1;
    for(int i=0; i<addressSize; i++){
        alo=alo*10;
    }
    int num=0;
    int arr[100];
    while(key>0){
        arr[num] = key%10;
        key/=10;
        num++;
    }
    int ans=0;
    int tmp=0, count=0;;
    for(int i=num-1; i>=0; i--){
        count++;
        tmp=tmp*10+arr[i];
        if(count==addressSize || i==0){
            ans=ans+tmp;
            ans=ans%alo;
            count=0;
            tmp=0;
        }
    }
    return ans;
}
int help_rotation(int arr[],int num, int addressSize){
        int alo=1;
    for(int i=0; i<addressSize; i++){
        alo=alo*10;
    }
        int ans=0;
    int tmp=0, count=0;;
    for(int i=num-1; i>=0; i--){
        count++;
        tmp=tmp*10+arr[i];
        if(count==addressSize || i==0){
            ans=ans+tmp;
            ans=ans%alo;
            count=0;
            tmp=0;
        }
    }
    return ans;
}
int rotation(long long key, int addressSize){
    int num=0;
    int arr[100];
    while(key>0){
        arr[num] = key%10;
        key/=10;
        num++;
    }
    arr[num]= arr[0];
    return help_rotation(arr+1, num, addressSize);
}
int main(){
    cout << rotation(1234567891234, 5);
}