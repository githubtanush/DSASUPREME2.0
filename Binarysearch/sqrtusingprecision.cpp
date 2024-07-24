#include<iostream>
using namespace std;
int mysqrt(int n){
    int s = 0;
    int e = n - 1;
    int mid = ( s + e)/2;
    int ans = -1;
    while(s<=e){
        if(mid*mid == n){
            ans = mid;
            s = mid + 1;
        }
        else if(mid*mid < n){
            s = mid + 1;
        }
        else{
            //bda hai 
            e = mid - 1;
        }
        mid = (s + e)/2;
    }
    return ans;
}
double myprecisionsqrt(int n){
    double sqrt = mysqrt(n);
    double step = 0.1;
    int precision = 20;
    for(int i = 0; i < precision;i++){
        double j = sqrt;
        while( j * j <= n){
            sqrt = (j+=step);
        }
        step = step / 10;
    }
    return sqrt;
}
int main(){
    int n;
    cout<<"Enter the number for which u find the sqaure root : ";
    cin>>n;
    double ans = myprecisionsqrt(n);
    cout<<"Square root of this number "<<n<<" is : "<<ans<<endl;
    return 0;
}