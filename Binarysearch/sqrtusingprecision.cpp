#include<iostream>
#include<iomanip>
using namespace std;
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
double myprecision(int n){
    double sqrt = mysqrt(n);
    //find kr liya na answer
    double step = 0.1;
    int precision = 10;
    for(int i = 0; i < precision;i++){
        double j = sqrt;
        while(j*j<=n){
            sqrt = j;
            j += step;
        }
        step = step / 10;
    }
    return sqrt;
}
int main(){
    int n;
    cout<<"Enter the number for which u find the square root : ";
    cin>>n;
    double ans = myprecision(n);
    cout<<"The sqrt for this following number is : "<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}