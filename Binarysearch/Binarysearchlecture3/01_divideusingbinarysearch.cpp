#include<iostream>
#include<iomanip>
using namespace std;
//quotient * divisor == divident quotient - finalanswer
//quotient * divisor < divident -> store answer and move right
//quotient * divisor > divident -> move left
int quotient(int divisor,int divident){
        int s = 0;
        int e = abs(divident);
        int ans = -1;
        while( s <= e ){
            int mid = s + ( e - s )/2;
            if(mid * divisor == divident) return mid;
            if(mid * abs(divisor) < divident){
                ans = mid ;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
}

int main(){
    int divisor;
    cout<<"Enter the divisor : ";
    cin>>divisor;
    int divident;
    cout<<"Enter the divident : ";
    cin>>divident;
    int ans = quotient(divisor,divident);
    //now we decide kon sa sign lagaye positive ya negative
    if((divisor > 0 && divident < 0) || (divisor < 0 && divident>0)) ans = 0 - ans;
    cout<<"Quotient for the following divident by this divisor is : "<<ans<<endl;

    return 0;
}
//7
//29