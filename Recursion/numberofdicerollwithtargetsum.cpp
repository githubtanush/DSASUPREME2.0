#include<iostream>
using namespace std;
int numrollstotarget(int n,int k,int target){
    //base case
    if(target<0) return 0;
    if(n==0 && target==0) return 1;
    if(n==0 && target!=0) return 0;
    if(n!=0 && target==0) return 0;

    int ans = 0;
    //for loop esliye taaki die ke hr faces ke liye ek baar recursive cases chl jay
    for(int i = 1; i <= k;i++){
        ans = ans + numrollstotarget(n-1,k,target-i);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int target;
    cin>>target;
    int ans = numrollstotarget(n,k,target);
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}
// 1 6 3
//output 1
// 2 6 7 
//output 6