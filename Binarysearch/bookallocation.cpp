#include<iostream>
#include<numeric>
using namespace std;
bool ispossiblesolution(int arr[],int n,int m,int sol){
    int pagesum = 0;
    int c = 1;
    for(int i = 0; i < n;i++){
        if(arr[i]>sol){
            return false;
        }
        if(pagesum + arr[i] > sol){
            c++;
            pagesum = arr[i];
            if(c>m){
                return false;
            }
        }
        else{
            pagesum += arr[i];
        }
    }
    return true;
}
long long findpages(int n,int arr[],int m){
    if(m>n) return -1;
    int s = 0;
    int e = accumulate(arr,arr+n,0);
    int ans = -1;
    while(s<=e){
        int mid = (s + e)>>1;
        if(ispossiblesolution(arr,n,m,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
   long long ans =  findpages(n,arr,m);
   cout<<"number of pages found from student is: "<<ans<<endl;
    return 0;
}
// 4
// 12 34 67 90
// 2