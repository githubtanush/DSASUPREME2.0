//Recursion -> base case -> mandatory
// recursion call -> mandatory
// processing -> optional
//code editor - 1 case mein solve krunga and baaki recursion sambhal lega
//Time and space complexity of recursion 
//To understand recursion you need to understand recursion
#include<iostream>
using namespace std;
long long int factorial(int n){
    //base case
    if(n<=1) return 1;

    //processing

    //recursive relation
    return n * factorial(n-1);
}
void reversecounting(int n){
    //base case 
    if(n == 0) return ;
    if(n == 1){
        cout<<1;
        return ;
    }

    //printing the n
    //processing
    cout<<n<<" ";
    //recursion
    reversecounting(n-1);

}
int power(int n){
    //base case
    if(n==0) return 1;
    //recursive relation
    return 2 * power(n-1);
}
//you must remember fibonnaci because this logic can apply in many big questions
int fibonnaciseries(int n){
    //base case
    if(n==0) return 0;
    if(n==1) return 1;

    //recursive relation
    return fibonnaciseries(n-1) + fibonnaciseries(n-2);


}
int sum(int n){
    //base case
    if(n == 1) return 1;

    //recursive relation
    return n + sum(n-1);
}
int main(){
    int n;
    cout<<"For which number do you find the factorial : ";
    cin>>n;
    cout<<"Factorial for the given number is : "<<factorial(n)<<endl;
    reversecounting(n);
    cout<<endl;
    cout<<"exponential power of 2 for given n is :"<<power(n)<<endl;
    cout<<"Fibonnaci pattern for this number is : "<<fibonnaciseries(n)<<endl;
    cout<<"Sum for N natural numbers is : "<<sum(n)<<endl;
    return 0;
}