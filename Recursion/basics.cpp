#include<iostream>
using namespace std;
// long long int factorial(int n){
//     // base case
//     if(n==0 || n==1) return 1;
//     //processing abhi to kuch nhi hai 
//     //recursive relation = 
//     return n * factorial(n-1);
// }
// void printcounting(int n){
//     //base case
//     if(n==1) {
//         cout<<1<<" ";
//         return ;
//     }
//     //proessing ulti counting tail recursion
//     // cout<<n<<" ";
//     //Recursive relation
//     printcounting(n-1);
//     //head recursion
//     cout<<n<<" ";
// }
int pow(int n){
    //basse case
    if(n==0) return 1;
    // cout<<pow(n)<<endl;
    //recursive relation
    return 2*pow(n-1);
}
int main(){
    int n;
    cin>>n;
//    long long int ans =  factorial(n);
int ans = pow(n);
// printcounting(n);
   cout<<ans<<endl;
   return 0;
}