#include<iostream>
#include<vector>
using namespace std;
// vector<int> twopointermethod(vector<int>& arr, int k, int x) {
// low ko mein 0 se initialize krunga
//     int l = 0;
// high ko array ke size se initialize krunga
//     int h = arr.size()-1;
// jab tak high - low window ke size se bda hai tab tak mein usme hera pheri krunga kyuki jab high - low < k ho gya matlab mere pass window form hogyi hai
//     while(h-l >= k){
//  x - arr[low] krne se mere pass difference aa jayga same assitice with arr[h] - x krne se difference aa jayga or x - arr[low] ka difference high se jada 
// hai toh pehle usko include krenge then baad mein high ko
//         if(x-arr[l] > arr[h]-x) l++;
// agr low ka difference km or high ka jada toh high-- hoga na
//         else h--;
//     }
// nya vector bnaya k size ka ans ko store krne ke liye
//     // vector<int> ans;
//     // for(int i = l ; i <= h;i++){
//     //     ans.push_back(arr[i]);
//     // }
//     // return ans;
//     //T.C - O(n) S.C - O(n-k)
//     //one more way to write upper thing is 
// return krdiya vector ek bina naya vector bnay 
//     return vector<int>(arr.begin()+l,arr.begin()+h+1);
// }




// 2nd approach - binary search + 2 pointer
//2.) find smallest element in the array which is >= x;
//3.) means find lowerbound which is closest element to X our case it is 35
//4.) high -> index closest element index
//5.) low -> high - 1;
//6.)[Low,high]->window->size->k
//7.) if(x - arr[low] > arr[high]-x) h++;
//8.) else low--;
int lowerbound(vector<int>& arr, int x ){
    int s = 0;
    int e = arr.size()-1;
    int ans = e;
    while(s<=e){
        int mid = (s + e)/2;
        if(arr[mid]>=x){
            ans = mid ;
            e = mid - 1;
        }
        else if(x > arr[mid]) s = mid + 1;
        else e = mid - 1;
    }
    return ans;

}
vector<int> bsmethod(vector<int>& arr, int k, int x) {
    //findlowerbound first
    //high sbse closest to x hai 
    int h = lowerbound(arr,x);
    //and low high se 1 kam hai 
    int l = h - 1;
    //jab tk k window ko km krrenge
    while(k--){
        //agr low < 0 ho gya to high++ krenge
        if(l<0) h++;
        //agr high >= arr.size() ho gya toh low-- krenge
        else if(h>=arr.size()) l--;
        //agr x-arr[l] bda hai arr[h] - x se to hm high ko move krenge kyuki hm expand krenge 
        else if(x-arr[l] > arr[h]-x) h++;
        else l--;
    }
    return vector<int>(arr.begin()+l+1,arr.begin()+h);

}
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // return twopointermethod(arr,k,x);
    return bsmethod(arr,k,x);
}
int main(){
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    int x;
    cin>>x;
    vector<int> ans = findClosestElements(nums,k,x);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}
// 13
// 12 16 22 30 35 39 42 45 48 50 53 55 56
// 4
// 35