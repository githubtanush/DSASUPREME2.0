#include<iostream>
using namespace std;
//mst algorithm hai 
//painting fence algorithm 
//jisme hmara pass n post hai or k colors hai 

int getpaintways(int n,int k){
    // base case 
    if(n==1)  return k;
    if(n==2) return k + (k * (k-1));
    
    //recursive case
      //finding the ways by analyzing the previous pattern
    return (k-1)*(getpaintways(n-1,k)+getpaintways(n-2,k));
}
int main(){
    int n;
    cin>>n;
    int k ;
    cin>>k;
    int ans = getpaintways(n,k);
    cout<<"answer for "<<n<<" is : "<<ans<<endl;
    return 0;
}