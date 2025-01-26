//climbing stairs ek question hai jisme yeh kehta hai 
//ki ek ya 2 step hi chl skta hai stairs par or hmko chadna hai 
//or destination par phunchna hai 
//or eska total number of ways nikalna hai
//total n stairs hai or hmko yeh btana ki kul kitna triko se hm chd 
//skte hai 0 to n stairs how many ways
#include<iostream>
#include<vector>
using namespace std;
int climbstairs(int n){
    //nth stairs par phunchna ka total number of ways kitna hai ?
    //nth stair -> total number of ways
    //f(n)->number of ways to reach nth stair is (n-1) and (n-2)

    //base case
    if(n==0 || n==1) return 1;

    //recursive relation 
    return climbstairs(n-1) + climbstairs(n-2);

}
int main(){
    int n;
    cout<<"Enter the value of which stair you want to reach : ";
    cin>>n;
    int ans =  climbstairs(n);
    cout<<"The total ways to climb the stairs is : "<<ans<<endl;
    return 0;
}