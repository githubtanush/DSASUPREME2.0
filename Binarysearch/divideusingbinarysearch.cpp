#include<iostream>
#include<iomanip>
using namespace std;
int quotient(int divisor,int divident){
        int s = 0;
        int e = divident;
        int ans = -1;
        while( s <= e ){
            int mid = s + ( e - s )/2;
            if(mid * divisor == divident) return mid;
            else if(mid * divisor < divident){
                ans = mid ;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
}
double getquotient(int divisor,int divident){
    double quotien = quotient(divisor,divident);
    int precision = 10;
    double step = 0.1;
    for(int i = 0; i < precision;i++){
        double j = quotien;
        while( j*divisor <= divident){
            quotien = j ;
            j += step ;
        }
        step = step/10;
    }
    return quotien;
}
int main(){
    int divisor;
    cin>>divisor;
    int divident;
    cin>>divident;
    double ans = getquotient(divisor,divident);
    cout<<"Quotient for the following divident by this divisor is : "<<fixed<<setprecision(10)<<ans<<endl;

    return 0;
}