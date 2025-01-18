#include<iostream>
#include<iomanip>
using namespace std;
//using the approach search space create 
//we can focus on search space 
//possible answer for 64 is the search space 
// //stl 
// sqrt (double)
// sqrtf (float)
// sqrtl (long double)
int mysqrt(int n){
    int s = 0;
    int e = n - 1;
    int mid = ( s + e )/2;
    int ans = -1;
    while(s <= e){
        if(mid*mid  <=  n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = (s + e)/2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number for which u find the square root : ";
    cin>>n;
    int ans = mysqrt(n);
    double ans1 = sqrt(n);
    cout<<"The sqrt for this following number is : "<<ans<<endl;
    cout<<"The sqrt for this following number is : "<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}