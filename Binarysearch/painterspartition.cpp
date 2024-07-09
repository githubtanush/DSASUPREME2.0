#include<iostream>
using namespace std;
bool ispossiblesolution(int arr[],int n,int k,long long mid){
    long long timesum = 0;
    int c = 1;
    for(int i = 0; i < n;i++){
        if(arr[i]>mid){
            return false;
        }
        if(arr[i] + timesum > mid){
            c++;
            timesum = arr[i];
            if(c>k) return false;
        }
        else timesum += arr[i];
    }
    return true;
}
long long mintime(int arr[],int n,int k){
    long long s = 0;
    long long e = 0;
    for(int i = 0; i < n;i++){
        e += arr[i];
    }
    long long ans = -1;
    while(s<=e){
        long long mid = s + ( e - s)/2;
        if(ispossiblesolution(arr,n,k,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    long long ans = mintime(arr,n,k);
    cout<<"The answer for this is : "<<ans<<endl;
    return 0;
}
// 5
// 5 10 30 20 15
// 3