#include<iostream>
#include<limits.h>
using namespace std;
int maximizethecuts(int n,int x,int y,int z){
    //base case 
    if(n==0) return 0;
    if(n<0) return INT_MIN;

    //processing
    //maine x length ka  1 segment cut krlia hai baaki recursion dekhlega
    int option1 = 1 + maximizethecuts(n-x,x,y,z);
    //maine y length ka 1 segment cut krlia hai baaki recursion dekhlega
    int option2 = 1 + maximizethecuts(n-y,x,y,z);
    //maine z length ka 1 segment cut krlia hai baaki recursion dekhlega
    int option3 = 1 + maximizethecuts(n-z,x,y,z);

    int finalans = max(option1,max(option2,option3));
    return finalans;
}
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int y;
    cin>>y;
    int z;
    cin>>z;
    int ans = maximizethecuts(n,x,y,z);
    cout<<"Maximize the cut segment will be : "<<ans<<endl;
    return 0;
}
//4 2 1 1