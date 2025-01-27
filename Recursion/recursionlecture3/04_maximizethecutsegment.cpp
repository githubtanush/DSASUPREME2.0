//cut into segments
#include<iostream>
#include<vector>
using namespace std;
int maximizethecuts(int n,int x,int y,int z){

    //base case
    if(n==0) return 0;
    if(n<0) return INT_MIN;

    //processing
    //meini x length ka ek segment cut kr liya then baaki recursion dekh lega
    int option1 = 1 + maximizethecuts(n-x,x,y,z);
    //meini y length ka ek segment cut kr liya then baaki recurison dekh lega
    int option2 = 1 + maximizethecuts(n-y,x,y,z);
    //meini z length ka ek segment cut kr liya then baaki recurison dekh lega
    int option3 = 1 + maximizethecuts(n-z,x,y,z);


    //final answer is 
    int finalans = max(option1,max(option2,option3));
    //return krdo final answer nu 
    return finalans;
}
int main(){
    int n;
    cout<<"The Length of the line segment is : ";
    cin>>n;

    int x;
    cout<<"The Length of the x segment is : ";
    cin>>x;

    int y;
    cout<<"The Length of the y segment is : ";
    cin>>y;

    int z;
    cout<<"The Length of the z segment is : ";
    cin>>z;

    int maximum = maximizethecuts(n,x,y,z);

    cout<<"The total number of cut segment must be maximum at : "<<maximum<<endl;

    return 0;
}